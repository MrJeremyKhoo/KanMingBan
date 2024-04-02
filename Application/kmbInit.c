#include "kmbInit.h"

ARRAY_OF_STRARRAY createKMBStruct(int maxStrLen, int numberColumns, int numberRows) {
  ARRAY_OF_STRARRAY KanMingBan = malloc(sizeof(char **)); 
  for(int i = 0; i < numberColumns; i++) {
    KanMingBan[i] =  malloc(sizeof(char*));  
    for(int j = 0; j < numberRows; j++) {
    KanMingBan[i][j] = malloc(sizeof maxStrLen * sizeof(char));
    }
  }
  return KanMingBan;
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
