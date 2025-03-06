#ifndef ADDPARSER_H
#define ADDPARSER_H
#include <stdio.h>
typedef char*** ARRAY_OF_STRARRAY;


void addTaskFile(char* task, char* header);
char* strreversechar(char *ptr, char target); 
long int getFileSize(FILE *fptr);

#endif
