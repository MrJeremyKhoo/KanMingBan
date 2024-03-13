#include "inputParser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char (*toDo)[100];
    char (*inProgress)[100];
    char (*Done)[100];
} KanMingBan;

void createKMBStruct(KanMingBan **KMBPtr) {
  *KMBPtr = (KanMingBan*)malloc(sizeof(KanMingBan));
  (*KMBPtr)->toDo = (char(*)[100])malloc(sizeof(char[100]));
  strcpy((*KMBPtr)->toDo[0], "hello");
}

void writeKMBColumn(KanMingBan **KMBPtr, int offset) {
}



void openFile() {
      FILE *fptr = fopen("kmb.dat", "r");

    if (fptr == NULL) {
        printf("Error opening file!\n");
    }
    
  KanMingBan *KMBPtr;

  createKMBStruct(&KMBPtr);

  printf("%s\n", (*KMBPtr).toDo[0]);

    char line[256]; 
    while (fgets(line, sizeof(line), fptr) != NULL) {
        printf("%s", line); 
    }

    fclose(fptr); 
}
