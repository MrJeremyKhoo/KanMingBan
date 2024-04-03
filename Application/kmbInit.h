#ifndef KMBINIT_H
#define KMBINIT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char*** ARRAY_OF_STRARRAY;

ARRAY_OF_STRARRAY createKMBStruct(int maxStrLen, int numberColumns, int numberRows);
void freeKanMingBanRows(ARRAY_OF_STRARRAY KanMingBan, int i, int numberRows);
void freeKanMingBan(ARRAY_OF_STRARRAY *KanMingBan, int numberColumns, int numberRows);

#endif
