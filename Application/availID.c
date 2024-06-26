#include "availID.h"
#include "errorHandler.h"
#include "../global.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

bool isEmpty(char *startSquareBracket, char *endSquareBracket) {
  return startSquareBracket == endSquareBracket;
}

int availID() {
    char filename[256]; // Adjust the size as per your needs
    snprintf(filename, sizeof(filename), "%s/%s", program_directory, "data/kmb.dat");
    FILE *fptr = fopen(filename, "r+");

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

    char *availIDTag = NULL;
    char *endSquareBracket= NULL;
    char *startSquareBracket= NULL;
    char* endIdChar = NULL;
    int num = 0;
    int oldLength = 0;
    // Find the first occurrence of the header
    availIDTag = strstr(buffer, "Avai-ID");
    endSquareBracket = strchr(availIDTag, ']');
    startSquareBracket = strchr(availIDTag, '[');
    
  // Skip over spaces and newlines between "[" and "]"
  while (*(++startSquareBracket) == ' ' || *startSquareBracket == '\n' || *startSquareBracket == '\r') {}
  //todo: assumption that largestID always have id
  if(isEmpty(startSquareBracket, endSquareBracket)) {
    availIDTag = strstr(buffer, "\"Largest-ID\":")+13;
    endIdChar = strchr(availIDTag, ',');
    while (*(++availIDTag) == ' ' || *availIDTag == '\n' || *availIDTag == '\r') {}
    num = strtol(availIDTag, &endIdChar, 10);
    oldLength = snprintf(NULL, 0, "%d", num) + 1;
    num++;    
    int length = snprintf(NULL, 0, "%d", num) + 1;
    char *str = (char *)malloc((length) * sizeof(char));
    snprintf(str, length, "%d", num);
     
    int position =  availIDTag - buffer;
    int commaPosition = endIdChar - buffer;
    int newSize = fileSize + length - oldLength;
    char *newBuffer = (char *)malloc(newSize);

    memcpy(newBuffer, buffer, position);
    memcpy(newBuffer + position, str, length);
    memcpy(newBuffer + position + length - 1, buffer + commaPosition, fileSize - commaPosition );

    fseek(fptr, 0, SEEK_SET);
    fwrite(newBuffer, 1, newSize, fptr); // -1 to exclude null terminator
    fseek(fptr, 0, SEEK_SET);
		fflush(fptr);
    fclose(fptr);
    free(newBuffer);
    free(buffer);
  
  } else {

    num = strtol(startSquareBracket, &endIdChar, 10);
    int length = snprintf(NULL, 0, "%d", num);
     
    int position =  endIdChar - buffer;
    int hasComma = (endIdChar != endSquareBracket);
    int newSize = fileSize - length - hasComma;
    char *newBuffer = (char *)malloc(newSize);
    memcpy(newBuffer, buffer, position - length);
    memcpy(newBuffer + position - length, buffer + position + hasComma, fileSize - position - hasComma);

    fseek(fptr, 0, SEEK_SET);
    fwrite(newBuffer, 1, newSize, fptr); // -1 to exclude null terminator
    fseek(fptr, 0, SEEK_SET);
		fflush(fptr);
    fclose(fptr);
    truncate("data/kmb.dat", newSize - 1);
    free(newBuffer);
    free(buffer);
  }


	return num;
}
