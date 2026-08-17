#ifndef ERRORHANDLER_H
#define ERRORHANDLER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void catchFileError(FILE *fptr);
void checkCharPointer(char *buffer);
void checkFileSize(size_t bytesRead, long int fileSize);
void checkParseError(void *ptr, const char *errorMessage);
void checkBoundsError(void *start, void *end, const char *errorMessage);
void checkMathError(int value, const char *errorMessage);

#endif
