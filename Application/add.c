#include "dataParser.h"
#include "../global.h"
#include "errorHandler.h"
#include "kmbInit.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* strreversechar(char *ptr, char target) {
    char* ptrz = 0;
    if (ptr == NULL) { 
        return NULL;
    }
    ptr--; // Move one position back
    // Search backwards 
    while (ptr > ptrz && *ptr != target) { 
        ptr--;
    }
    // Check if found
    if (ptr > ptrz) { 
        return ptr;
    } else {
        return NULL; 
    }   
}

long int getFileSize(FILE *fptr) {
    fseek(fptr, 0, SEEK_END);
    long int fileSize = ftell(fptr);
    return fileSize;

}

void addTaskFile(char* task, char* header) {
    char filename[256]; // Adjust the size as per your needs
    snprintf(filename, sizeof(filename), "%s/%s", program_directory, "data/kmb.dat");
    FILE *fptr = fopen(filename, "rb+");
    if (fptr == NULL) {
        perror("Error opening file");
        return;
    }

    long int fileSize = getFileSize(fptr);

    // Allocate memory dynamically for the file content
    char *buffer = (char *)malloc(fileSize + 1); // +1 for null terminator
		checkCharPointer(buffer);
    size_t bytesRead = fread(buffer, 1, fileSize, fptr);
		checkFileSize(bytesRead, fileSize);
    buffer[fileSize] = '\0'; // Null-terminate the string

    char *lastHeader = NULL;
    char *lastClosingBracket = NULL;
    char *openingBracket = NULL;
    char *lastCurlyClosing = NULL;
    char *insertion = NULL;
    char *headerTag = NULL;
    char *headerEnd = NULL;

    // Find the last occurrence of the header
    headerTag = strstr(buffer, "HEADER");
    headerEnd = strchr(headerTag, ']');
    lastHeader = strstr(headerEnd, header);

    char new_str[strlen(task)+5];
    snprintf(new_str, strlen(task)+5, ",\n\t\t%s", task);
		task = new_str;
    // Find the last occurrence of ']'
    lastClosingBracket = strchr(lastHeader, ']');
    openingBracket = strchr(lastHeader, '[');
    lastCurlyClosing = strchr(lastHeader, '}');
    
    while (*(++openingBracket) == ' ' || *openingBracket == '\n' || *openingBracket == '\r') {}
    if(openingBracket == lastClosingBracket) {
      insertion = lastClosingBracket ;
      task += 1;
    } else {
      insertion = lastCurlyClosing+ 1;
    }
    
    
    // Calculate the position to insert the task
    int position =  insertion - buffer;
    // Create new buffer with enough space for the new task and null terminator
    int taskLen = strlen(task);
    int newSize = fileSize + taskLen;
    char *newBuffer = (char *)malloc(newSize);

    // Copy the original content up to the insertion point
    memcpy(newBuffer, buffer, position);

    // Insert the task
    memcpy(newBuffer + position, task, taskLen);

    // Copy the rest of the original content
    memcpy(newBuffer + position + taskLen, buffer + position, fileSize - position);

    // Write the new buffer back to the file
    fseek(fptr, 0, SEEK_SET);
    fwrite(newBuffer, 1, newSize, fptr); // -1 to exclude null terminator
		fflush(fptr);
    fclose(fptr);
    free(newBuffer);
    free(buffer);
	return;
}
