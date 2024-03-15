#include "inputParser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char*** ARRAY_OF_STRARRAY;

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

void openFile() {
  FILE *fptr = fopen("kmb.dat", "r");

  if (fptr == NULL) {
      printf("Error opening file!\n");
  }
    
  ARRAY_OF_STRARRAY KanMingBan = createKMBStruct(100, 3, 100);

  char line[256]; 
  while (fgets(line, sizeof(line), fptr) != NULL) {
      printf("%s", line); 
  }

  fclose(fptr); 
}
