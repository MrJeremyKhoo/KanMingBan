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
    PTR_STR_ARRAY toDo = malloc(sizeof(char *));
    PTR_STR_ARRAY inProgress = malloc(sizeof(char *));
    PTR_STR_ARRAY done = malloc(sizeof(char *));

    toDo[0] = malloc(MAXSTRLEN * sizeof(char));  // Space for strings
    toDo[1] = malloc(MAXSTRLEN * sizeof(char));  // Space for strings
    inProgress[0] = malloc(MAXSTRLEN * sizeof(char));  // Space for strings
    strcpy(toDo[0], "hehe");
    strcpy(toDo[1], "hoho");
    strcpy(inProgress[0], "haha");

    ARRAY_PTR_STR_ARRAY KanMingBan = malloc(sizeof(char **) * 1); 
    KanMingBan[0] = toDo;
    KanMingBan[1] = inProgress;
  printf(KanMingBan[0][0]);
  printf(KanMingBan[0][1]);
  printf(KanMingBan[1][0]);
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
