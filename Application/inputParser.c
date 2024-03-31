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
//------------

void parseFileIntoKMB(FILE *fptr, ARRAY_OF_STRARRAY KanMingBan) {
  char line[100]; 
  while (fgets(line, sizeof(line), fptr) != NULL) {
    char *header_start = strstr(line, "\"HEADER\":");
    printf(header_start);
    printf("%s", line); 
  }

}

void catchFileError(FILE *fptr) {
  if (fptr == NULL) {
    printf("File does not exist. Creating a new file.\n");
    fptr = fopen("kmb.dat", "w"); // Opening in write mode to create the file
    if (fptr == NULL) {
      printf("Error creating file!\n");
      return;
    }
  }

}


void openFile() {
  FILE *fptr = fopen("data/kmb.dat", "r");
  ARRAY_OF_STRARRAY KanMingBan = createKMBStruct(100, 3, 100);
  parseFileIntoKMB(fptr, KanMingBan); 
  fclose(fptr); 
}
