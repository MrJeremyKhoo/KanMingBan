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
      // Determine the size of the file
    fseek(fptr, 0, SEEK_END);
    long int fileSize = ftell(fptr);
    fseek(fptr, 0, SEEK_SET);
    printf("File size: %ld bytes\n", fileSize);
      // Allocate memory dynamically for the file content
    char *buffer = (char *)malloc(fileSize + 1); // Plus 1 for null terminator
    if (buffer == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Read the file content into the buffer
    size_t bytesRead = fread(buffer, 1, fileSize, fptr);
    if (bytesRead != fileSize) {
        fprintf(stderr, "Error reading file\n");
        exit(1);
    }
    buffer[fileSize] = '\0'; // Null-terminate the string

    // Now 'buffer' contains the content of the file

    char *header_start = strstr(buffer, "\"HEADER\":");
    char *header_end = strchr(header_start, '\n');
    if (header_end != NULL) {
        // Calculate the length of the header
        size_t header_length = header_end - header_start;
        // Print the header content
        printf("Header content:\n%.*s\n", (int)header_length, header_start);
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
