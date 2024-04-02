#include "dataParser.h"
#include "errorHandler.h"
#include "kmbInit.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parseHeaderToKmb (char* buffer, ARRAY_OF_STRARRAY KanMingBan) {
  char *header_start = strstr(buffer, "\"HEADER\":");
  char *header_opening_bracket = strchr(header_start, '[');
  char *header_ending_bracket = strchr(header_start + 1, ']');
  char *start_doublequote = strchr(header_opening_bracket, '\"');
  char *end_doublequote = strchr(start_doublequote + 1, '\"');
  int task_length = end_doublequote - start_doublequote - 1;
  //some error catching needed here
  size_t i = 0;
  while(start_doublequote < header_ending_bracket) {
    strncpy(KanMingBan[i][0], start_doublequote + 1, task_length);
    KanMingBan[i][0][task_length] = '\0';
    start_doublequote = strchr(end_doublequote + 1, '\"');
    end_doublequote = strchr(start_doublequote + 1, '\"');
    task_length = end_doublequote - start_doublequote - 1;
    printf("%s\n", KanMingBan[i][0]);
    i++;
  }

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
  buffer[fileSize] = '\0'; // Null-terminate the string
  parseHeaderToKmb(buffer, KanMingBan);
}

ARRAY_OF_STRARRAY openFile() {
  FILE *fptr = fopen("data/kmb.dat", "r");
  ARRAY_OF_STRARRAY KanMingBan = createKMBStruct(100, 3, 100);
  parseFileIntoKMB(fptr, KanMingBan); 
  fclose(fptr); 
  return KanMingBan;
}
