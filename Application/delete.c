#include "errorHandler.h"
#include "add.h"
#include "../global.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void deleteTaskFile(char* id) {
    char filename[256]; // Adjust the size as per your needs
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
    char *buffer = (char *)malloc(fileSize + 1); // +1 for null terminator
		checkCharPointer(buffer);
    size_t bytesRead = fread(buffer, 1, fileSize, fptr);
		checkFileSize(bytesRead, fileSize);
    buffer[fileSize] = '\0'; // Null-terminate the string

    char *lastHeader = NULL;
    char *lastClosingBracket = NULL;

    char* idplace = strstr(buffer, id);
    char* openingClosingBracket = strreversechar(idplace, ',');
    char* firstSquareBracket = strreversechar(idplace, '[');
    if(openingClosingBracket < firstSquareBracket) {
      openingClosingBracket = firstSquareBracket + 1;
    }
    lastClosingBracket = strchr(openingClosingBracket, '}');

    // Calculate the position to insert the task
    int position = openingClosingBracket - buffer;
    // Create new buffer with enough space for the new task and null terminator
    int taskLen =  lastClosingBracket - openingClosingBracket;
    int newSize = fileSize - taskLen;
    char *newBuffer = (char *)malloc(newSize);

    // Copy the original content up to the insertion point
    memcpy(newBuffer, buffer, position);

    // Copy the rest of the original content
    memcpy(newBuffer + position, buffer + position + taskLen + 1, fileSize - position - taskLen);

    // Write the new buffer back to the file
    fseek(fptr, 0, SEEK_SET);
    fwrite(newBuffer, 1, newSize, fptr); // -1 to exclude null terminator
    fseek(fptr, 0, SEEK_SET);
		fflush(fptr);
    fclose(fptr);
    truncate(filename, newSize - 1);
    free(newBuffer);
    free(buffer);
	return;
}
