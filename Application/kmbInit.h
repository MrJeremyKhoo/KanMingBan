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
void freeKanMingBan(struct kmb *kmb, int numberColumns, int numberRows);

#endif
