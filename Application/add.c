#include "dataParser.h"
#include "errorHandler.h"
#include "kmbInit.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void addTaskFile(char* task, char* header) {
    FILE *fptr = fopen("data/kmb.dat", "r+");
    if (fptr == NULL) {
        perror("Error opening file");
        return;
    }

    char new_str[strlen(task)+4];
    snprintf(new_str, strlen(task)+4, ",\"%s\"", task);
		task = new_str;

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
    char *headerTag = NULL;
    char *headerEnd = NULL;

    // Find the last occurrence of the header
    headerTag = strstr(buffer, "HEADER");
    headerEnd = strchr(headerTag, ']');
    lastHeader = strstr(headerEnd, header);

    // Find the last occurrence of ']'
    lastClosingBracket = strchr(lastHeader, ']');

    // Calculate the position to insert the task
    int position = lastClosingBracket - buffer;
    // Create new buffer with enough space for the new task and null terminator
    int taskLen = strlen(task);
    int newSize = fileSize + taskLen + 1;
    char *newBuffer = (char *)malloc(newSize);

    // Copy the original content up to the insertion point
    memcpy(newBuffer, buffer, position);

    // Insert the task
    memcpy(newBuffer + position, task, taskLen);

    // Copy the rest of the original content
    memcpy(newBuffer + position + taskLen, buffer + position, fileSize - position);

    // Write the new buffer back to the file
    fseek(fptr, 0, SEEK_SET);
    fwrite(newBuffer, 1, newSize - 1, fptr); // -1 to exclude null terminator
		fflush(fptr);
		fclose(fptr);
    free(newBuffer);
    free(buffer);
	return;
}
