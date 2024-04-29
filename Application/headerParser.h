#ifndef HEADERPARSER_H
#define HEADERPARSER_H
#include <stdio.h>
#include "kmbInit.h"
typedef char*** ARRAY_OF_STRARRAY;

void parseHeaderToKmb(char** buffer, struct kmb *pkmb1);
void parseHeaderToArray(char* buffer, char *** array);

#endif
