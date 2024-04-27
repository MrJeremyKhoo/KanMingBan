#include "makeAvailID.h"
#include "errorHandler.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>


void makeAvailID(int id) {
    FILE *fptr = fopen("data/kmb.dat", "r+");

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
    char *largestNum= NULL;
    char* endIdChar = NULL;
    long num = 0;
    long oldLength = 0;
    // Find the first occurrence of the header
    availIDTag = strstr(buffer, "Avai-ID");
    endSquareBracket = strchr(availIDTag, ']');
    startSquareBracket = strchr(availIDTag, '[');
    
  // Skip over spaces and newlines between "[" and "]"
  while (*(++startSquareBracket) == ' ' || *startSquareBracket == '\n' || *startSquareBracket == '\r') {}
  
  char *newBuffer = NULL;
  char *str = NULL;
  int position = 0;
  int newSize = 0;
  int length = 0;

  if(startSquareBracket == endSquareBracket) {
    length = snprintf(NULL, 0, "%d", id);
    char* preStr = malloc(length * sizeof(char) + 1);
    snprintf(preStr, length + 1, "%d", id);

    position =  startSquareBracket - buffer;
    newSize = fileSize + length;
    newBuffer = (char *)malloc(newSize);
    str = preStr;
  
  } else {
    length = snprintf(NULL, 0, "%d,", id);
    char* preStr = malloc(length * sizeof(char) + 2);
    snprintf(preStr, length+1, "%d,", id);

    position =  startSquareBracket - buffer;
    newSize = fileSize + length;
    newBuffer = (char *)malloc(newSize);
    str = preStr;

  }

    memcpy(newBuffer, buffer, position);
    memcpy(newBuffer + position, str, length);
    memcpy(newBuffer + position + length, buffer + position, fileSize - position);

    fseek(fptr, 0, SEEK_SET);
    fwrite(newBuffer, 1, newSize, fptr); // -1 to exclude null terminator
    fseek(fptr, 0, SEEK_SET);
		fflush(fptr);
    fclose(fptr);
    free(newBuffer);
    free(buffer);
}
