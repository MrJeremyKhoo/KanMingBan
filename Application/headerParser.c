#include "dataParser.h"
#include "errorHandler.h"
#include "kmbInit.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copystr(char* pointer, struct kmb *pkmb1, int length, int i, int j) {
      for (int k = 0; k < length; ++k) {
        pkmb1->KanMingBan[i][j][k] = pointer[k+1];
      }


}
void parseHeaderToKmb (char** buffer, struct kmb *pkmb1 ) {
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
    copystr(start_doublequote, pkmb1, task_length, i, 0);
    for (int k = 0; k < task_length; ++k) {
      pkmb1->Header[i][k] = (start_doublequote[k+1]);
    }
    pkmb1->KanMingBan[i][0][task_length] = '\0';
    start_doublequote = strchr(end_doublequote + 1, '\"');
    end_doublequote = strchr(start_doublequote + 1, '\"');
    task_length = end_doublequote - start_doublequote - 1;
    i++;
  }
  *buffer = header_ending_bracket;
  pkmb1->Header[i] = NULL;
}
//todo:when last column no task it crashes
void parseTaskToKmb (char* buffer, struct kmb *pkmb1 ) {
  size_t i = 0;
  size_t max_j = 1;
  while(pkmb1->Header[i] != NULL) {
    char *header_start = strstr(buffer, pkmb1->Header[i]);
    char *header_opening_bracket = strchr(header_start, '[');
    char *header_ending_bracket = strchr(header_start + 1, ']');
    char *start_doublequote = strchr(header_opening_bracket, '\"');
    char *end_doublequote = strchr(start_doublequote + 1, '\"');
    int task_length = end_doublequote - start_doublequote - 1;

    size_t j = 1;
    while(start_doublequote < header_ending_bracket) {
      for (int k = 0; k < task_length; ++k) {
        pkmb1->KanMingBan[i][j][k] = (start_doublequote[k+1]);
      }
      pkmb1->KanMingBan[i][j][task_length] = '\0';
      start_doublequote = strchr(end_doublequote + 1, '\"');
      if(start_doublequote == NULL) {
        j++;
        break;
      }//end of file
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
  struct kmb *pkmb1 = createKanMingBan(100, 100, 10);
  parseFileIntoKMB(fptr, pkmb1); 
  fclose(fptr);
  return *pkmb1;
}
