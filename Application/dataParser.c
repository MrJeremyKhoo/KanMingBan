#include "dataParser.h"
#include "errorHandler.h"
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

void headerParser (char* buffer, ARRAY_OF_STRARRAY KanMingBan) {

}

void parseFileIntoKMB(FILE *fptr, ARRAY_OF_STRARRAY KanMingBan) {
  // Determine the size of the file
  fseek(fptr, 0, SEEK_END);
  long int fileSize = ftell(fptr);
  fseek(fptr, 0, SEEK_SET);
  printf("File size: %ld bytes\n", fileSize);

  // Allocate memory dynamically for the file content
  char *buffer = (char *)malloc(fileSize + 1); // Plus 1 for null terminator
  checkCharPointer(buffer);

  size_t bytesRead = fread(buffer, 1, fileSize, fptr);
  checkFileSize(bytesRead, fileSize);
  fclose(fptr);
  buffer[fileSize] = '\0'; // Null-terminate the string

  // Now 'buffer' contains the content of the file
  char *header_start = strstr(buffer, "\"HEADER\":");
  char *header_end = strchr(header_start, '\n');
  char *header_opening_bracket = strchr(header_start, '[');
  char *header_ending_bracket = strchr(header_start + 1, ']');
  char *start_doublequote = strchr(header_opening_bracket, '\"');
  char *end_doublequote = strchr(start_doublequote + 1, '\"');
  size_t task_length = end_doublequote - start_doublequote - 1;
  strncpy(KanMingBan[0][0], start_doublequote + 1, task_length);
  KanMingBan[0][0][task_length] = '\0';
  printf("%s\n", KanMingBan[0][0]);

  start_doublequote = strchr(end_doublequote + 1, '\"');
  end_doublequote = strchr(start_doublequote + 1, '\"');
  task_length = end_doublequote - start_doublequote - 1;
  strncpy(KanMingBan[1][0], start_doublequote + 1, task_length);
  KanMingBan[1][0][task_length] = '\0';
  printf("%s\n", KanMingBan[1][0]);

  if (header_end != NULL) {
    // Calculate the length of the header
    size_t header_length = header_end - header_start;
    // Print the header content
    printf("Header content:\n%.*s\n", (int)header_length, header_start);
  }

}



void openFile() {
  FILE *fptr = fopen("data/kmb.dat", "r");
  ARRAY_OF_STRARRAY KanMingBan = createKMBStruct(100, 3, 100);
  parseFileIntoKMB(fptr, KanMingBan); 
  fclose(fptr); 
}
