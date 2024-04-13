#include "dataParser.h"
#include "errorHandler.h"
#include "kmbInit.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct kmb parseHeaderToKmb (char** buffer, struct kmb kmb1 ) {
  char *b = *buffer;
  char *header_start = strstr(b, "\"HEADER\":");
  char *header_opening_bracket = strchr(header_start, '[');
  char *header_ending_bracket = strchr(header_start + 1, ']');
  char *start_doublequote = strchr(header_opening_bracket, '\"');
  char *end_doublequote = strchr(start_doublequote + 1, '\"');
  int task_length = end_doublequote - start_doublequote - 1;
  //some error catching needed here
  size_t i = 0;
  while(start_doublequote < header_ending_bracket) {
    strncpy(kmb1.KanMingBan[i][0], start_doublequote + 1, task_length);
    strncpy(kmb1.Header[i], start_doublequote + 1, task_length);
    kmb1.KanMingBan[i][0][task_length] = '\0';
    start_doublequote = strchr(end_doublequote + 1, '\"');
    end_doublequote = strchr(start_doublequote + 1, '\"');
    task_length = end_doublequote - start_doublequote - 1;
    i++;
  }
  *buffer = header_ending_bracket;
  kmb1.Header[i] = NULL;
  return kmb1;
}

struct kmb parseTaskToKmb (char* buffer, struct kmb kmb1 ) {
  for (int i = 0; kmb1.Header[i] != NULL; ++i) {
    char *header_start = strstr(buffer, kmb1.Header[i]);
    char *header_opening_bracket = strchr(header_start, '[');
    char *header_ending_bracket = strchr(header_start + 1, ']');
    char *start_doublequote = strchr(header_opening_bracket, '\"');
    char *end_doublequote = strchr(start_doublequote + 1, '\"');
    int task_length = end_doublequote - start_doublequote - 1;

    size_t j = 1;
    while(start_doublequote < header_ending_bracket) {
      strncpy(kmb1.KanMingBan[i][j], start_doublequote + 1, task_length);
      kmb1.KanMingBan[i][j][task_length] = '\0';
      start_doublequote = strchr(end_doublequote + 1, '\"');
      if(start_doublequote == NULL) {
        j++;
        break;
      }//end of file
      end_doublequote = strchr(start_doublequote + 1, '\"');
      task_length = end_doublequote - start_doublequote - 1;
      j++;
    }
    kmb1.KanMingBan[i][j] = NULL;
  };
  return kmb1;
}

struct kmb parseFileIntoKMB(FILE *fptr, struct kmb kmb1) {
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
  kmb1 = parseHeaderToKmb(&buffer, kmb1);
  return kmb1 = parseTaskToKmb(buffer, kmb1);
}

struct kmb openFile() {
  FILE *fptr = fopen("data/kmb.dat", "r");
  struct kmb kmb1 = createKanMingBan(100, 3, 100);
  kmb1 = parseFileIntoKMB(fptr, kmb1); 
  fclose(fptr);
  return kmb1;
}
