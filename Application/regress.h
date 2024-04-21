#ifndef REGRESS_H
#define REGRESS_H
#include <stdio.h>
//todo: not open header twice, once for this command, then for kmbinit
#include "headerParser.h"
typedef char*** ARRAY_OF_STRARRAY;


void regressTaskFile(char* id);

#endif
