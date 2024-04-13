#include "kmbInit.h"


struct kmb createKanMingBan(int maxStrLen, int numberColumns, int numberRows) {
  ARRAY_OF_STRARRAY KanMingBan = malloc(numberColumns * sizeof(char **)); 
  for(int i = 0; i < numberColumns; i++) {
    KanMingBan[i] =  malloc(numberRows * sizeof(char*));  
    for(int j = 0; j < numberRows; j++) {
    KanMingBan[i][j] = malloc(maxStrLen * sizeof(char));
    }
  }

  char ** Header = malloc(sizeof(char*));
  for(int i = 0; i < numberColumns; i++) {
    Header[i] = malloc(maxStrLen * sizeof(char));
  }
  struct kmb kmb1;
  kmb1.KanMingBan = KanMingBan;
  kmb1.Header = Header;
  
  return kmb1;
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


