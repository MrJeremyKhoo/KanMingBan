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
    char *array_opening_bracket = strchr(header_start, '[');
    char *array_ending_bracket = strchr(header_start + 1, ']');
    char *name_start_doublequote = strstr(array_opening_bracket, "name\": \"")+7;
    char *id = strstr(array_opening_bracket, "name\": \"")+7;
    if(name_start_doublequote == NULL) {
      break;
    } //last header no file
    char *name_end_doublequote = strchr(name_start_doublequote + 1, '\"');
    int task_length = name_end_doublequote - name_start_doublequote - 1;

    size_t j = 1;
    while(name_start_doublequote < array_ending_bracket) {
      strncpy(pkmb1->KanMingBan[i][j], name_start_doublequote+1, task_length);
      pkmb1->KanMingBan[i][j][task_length] = '\0';
      name_start_doublequote = strstr(name_end_doublequote + 1, "name\": \"");
      if(name_start_doublequote == NULL) {
        j++;
        break;
      }//end of file
      name_start_doublequote += 7;
      name_end_doublequote = strchr(name_start_doublequote + 1, '\"');
      task_length = name_end_doublequote - name_start_doublequote - 1;
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
  struct kmb *pkmb1 = createKanMingBan(10, 3, 20);
  parseFileIntoKMB(fptr, pkmb1); 
  fclose(fptr);
  return *pkmb1;
}
