#include "inputParser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSTRLEN 100
#define MAXCOLUMNS 3
#define MAXROWS 100

typedef char** PTR_STR_ARRAY;
typedef char*** ARRAY_PTR_STR_ARRAY;

void createKMBStruct() {
    PTR_STR_ARRAY toDo = malloc(MAXROWS * sizeof(char *));
    PTR_STR_ARRAY inprogress = malloc(MAXROWS * sizeof(char *));
    PTR_STR_ARRAY done = malloc(MAXROWS * sizeof(char *));

    toDo[0] = malloc(MAXSTRLEN * sizeof(char));  // Space for strings
    strcpy(toDo[0], "hehe");

    ARRAY_PTR_STR_ARRAY KanMingBan = malloc(sizeof(char **) * MAXCOLUMNS); 
    KanMingBan[0] = toDo;
  printf(KanMingBan[0][0]);
}

void openFile() {
  FILE *fptr = fopen("kmb.dat", "r");

  if (fptr == NULL) {
      printf("Error opening file!\n");
  }
    
  createKMBStruct();

  char line[256]; 
  while (fgets(line, sizeof(line), fptr) != NULL) {
      printf("%s", line); 
  }

  fclose(fptr); 
}
