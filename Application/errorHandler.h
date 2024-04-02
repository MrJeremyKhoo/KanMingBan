#ifndef ERRORHANDLER_H
#define ERRORHANDLER_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void catchFileError(FILE *fptr);
void checkCharPointer(char *buffer);
void checkFileSize(size_t byteRead, long int fileSize);

#endif
