#ifndef KMBINIT_H
#define KMBINIT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char*** ARRAY_OF_STRARRAY;

struct kmb {
  ARRAY_OF_STRARRAY KanMingBan;
  char** Header;
  int column;
  int row;
};

struct kmb* createKanMingBan(int maxStrLen, int numberColumns, int numberRows);
void freeKanMingBanRows(ARRAY_OF_STRARRAY KanMingBan, int i, int numberRows);
void freeKanMingBan(ARRAY_OF_STRARRAY *KanMingBan, int numberColumns, int numberRows);

#endif
