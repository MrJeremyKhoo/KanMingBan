#include "dataParser.h"
#include "add.h"
#include "headerParser.h"
#include "errorHandler.h"
#include "kmbInit.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parseTaskToKmb (char* buffer, struct kmb *pkmb1 ) {
  size_t i = 0;
  size_t max_j = 1;
  while(pkmb1->Header[i] != NULL) {
    char *header_start = strstr(buffer, pkmb1->Header[i]);
    char *header_opening_bracket = strchr(header_start, '[');
    char *header_ending_bracket = strchr(header_start + 1, ']');
    char *start_doublequote = strstr(header_opening_bracket, "name\": \"")+7;
    if(start_doublequote == NULL) {
      break;
    } //last header no file
    char *end_doublequote = strchr(start_doublequote + 1, '\"');
    int task_length = end_doublequote - start_doublequote - 1;

    size_t j = 1;
    while(start_doublequote < header_ending_bracket) {
      strncpy(pkmb1->KanMingBan[i][j], start_doublequote+1, task_length);
      pkmb1->KanMingBan[i][j][task_length] = '\0';
      start_doublequote = strstr(end_doublequote + 1, "name\": \"");
      if(start_doublequote == NULL) {
        j++;
        break;
      }//end of file
      start_doublequote += 7;
      end_doublequote = strchr(start_doublequote + 1, '\"');
      task_length = end_doublequote - start_doublequote - 1;
      j++;
    }
    if (j>max_j) {max_j = j;}
    i++;
  };
  pkmb1->column = i;
  pkmb1->row = max_j;
}

void parseFileIntoKMB(FILE *fptr, struct kmb *pkmb1) {
  // Determine the size of the file
  fseek(fptr, 0, SEEK_END);
  long int fileSize = ftell(fptr);
  fseek(fptr, 0, SEEK_SET);
  // Allocate memory dynamically for the file content
  char *buffer = (char *)malloc(fileSize + 1); // Plus 1 for null terminator
  checkCharPointer(buffer);
  size_t bytesRead = fread(buffer, 1, fileSize, fptr);
  checkFileSize(bytesRead, fileSize);
  buffer[fileSize] = '\0'; // Null-terminate the string
  parseHeaderToKmb(&buffer, pkmb1);
  parseTaskToKmb(buffer, pkmb1);
}

struct kmb openFile() {
  FILE *fptr = fopen("data/kmb.dat", "r");
  struct kmb *pkmb1 = createKanMingBan(100, 100, 100);
  parseFileIntoKMB(fptr, pkmb1); 
  fclose(fptr);
  return *pkmb1;
}
