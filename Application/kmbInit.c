#include "kmbInit.h"


struct kmb* createKanMingBan(int maxStrLen, int numberColumns, int numberRows) {
  ARRAY_OF_STRARRAY KanMingBan = calloc(numberColumns, sizeof(char **)); 
  for(int i = 0; i < numberColumns; i++) {
    KanMingBan[i] =  calloc(numberRows, sizeof(char*));  
    for(int j = 0; j < numberRows; j++) {
    KanMingBan[i][j] = calloc(maxStrLen, sizeof(char));
    }
  }

  char ** Header = calloc(numberColumns, sizeof(char*));
  for(int i = 0; i < numberColumns; i++) {
    Header[i] = (char*)calloc(maxStrLen, sizeof(char));
  }
  struct kmb *pkmb1 = malloc(sizeof(struct kmb));
  pkmb1->KanMingBan = KanMingBan;
  pkmb1->Header = Header;

  return pkmb1;
}

//free methods
void freeKanMingBanRows(ARRAY_OF_STRARRAY KanMingBan, int i, int numberRows) {
    for (int j = 0; j < numberRows; j++) {
      free(KanMingBan[i][j]);
    }
}

void freeKanMingBan(ARRAY_OF_STRARRAY *KanMingBan, int numberColumns, int numberRows) {
  for (int i = 0; i < numberColumns; i++) {
    freeKanMingBanRows(*KanMingBan, i, numberRows);
    free(KanMingBan[i]); 
  }
  free(KanMingBan);
  KanMingBan = NULL;
}


