#include "errorHandler.h"
#include "add.h"
#include "../global.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void deleteTaskFile(char* id) {
    char filename[256];
    snprintf(filename, sizeof(filename), "%s/%s", program_directory, "data/kmb.dat");
    
    FILE *fptr = fopen(filename, "rb+");
    if (fptr == NULL) {
        perror("Error opening file");
        return;
    }

    // Determine the size of the file
    fseek(fptr, 0, SEEK_END);
    long int fileSize = ftell(fptr);
    fseek(fptr, 0, SEEK_SET);

    // Allocate memory dynamically for the file content
    char *buffer = (char *)malloc(fileSize + 1);
    checkCharPointer(buffer);
    
    size_t bytesRead = fread(buffer, 1, fileSize, fptr);
    checkFileSize(bytesRead, fileSize);
    buffer[fileSize] = '\0'; // Null-terminate the string

    // 1. Find the ID in the file
    char* idplace = strstr(buffer, id);
    checkParseError(idplace, "Error: Task ID not found in data file.");

    // 2. Find the start of the task safely
    char* comma = strreversechar(idplace, ',');
    char* bracket = strreversechar(idplace, '[');
    char* startPoint = NULL;

    // Safely determine where to start cutting (handling cases where one might be NULL)
    if (comma != NULL && bracket != NULL) {
        startPoint = (comma > bracket) ? comma : (bracket + 1);
    } else if (comma != NULL) {
        startPoint = comma;
    } else if (bracket != NULL) {
        startPoint = bracket + 1;
    } else {
        // If both are NULL, trigger the error handler
        checkParseError(NULL, "Error: Could not find start boundary of task.");
    }

    // 3. Find the end of the task
    char *endPoint = strchr(startPoint, '}');
    checkParseError(endPoint, "Error: Could not find closing brace '}' for task.");

    // 4. Validate memory boundaries before doing ANY math
    checkBoundsError(startPoint, endPoint, "Error: Task memory boundaries are corrupted.");

    // 5. Calculate sizes safely
    int position = startPoint - buffer;
    int taskLen = endPoint - startPoint;
    checkMathError(taskLen, "Error: Task length calculation is invalid.");
    
    int newSize = fileSize - taskLen;
    checkMathError(newSize, "Error: New file size calculation is invalid.");

    // 6. Create the new buffer and stitch the file back together
    char *newBuffer = (char *)malloc(newSize);
    checkCharPointer(newBuffer);

    // Copy the original content up to the insertion point
    memcpy(newBuffer, buffer, position);
    
    // Copy the rest of the original content (skipping over the deleted task)
    memcpy(newBuffer + position, endPoint + 1, fileSize - position - taskLen);

    // 7. Write the new buffer back to the file
    fseek(fptr, 0, SEEK_SET);
    fwrite(newBuffer, 1, newSize, fptr); 
    fflush(fptr);
    fclose(fptr);
    
    truncate(filename, newSize - 1);
    
    free(newBuffer);
    free(buffer);
}
