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
    char *array_ending_bracket = strchr(header_start, ']');
    char *name_start_doublequote = strstr(array_opening_bracket, "name\": \"")+8; //8 is number of charc till actual name
    char *id_start = strstr(array_opening_bracket, "id\": ")+5;
    char *id_end = strchr(id_start, ',');
    if(name_start_doublequote == NULL) {
      break;
    } //last header no file
    char *name_end_doublequote = strchr(name_start_doublequote, '\"');
    int task_length = name_end_doublequote - name_start_doublequote;
    int id_length = id_end - id_start;

    size_t j = 1;
    while(name_start_doublequote < array_ending_bracket) {
      char *id = malloc(id_length * sizeof(char));
      char *task = malloc(task_length * sizeof(char));
      strncpy(id, id_start, id_length);
      strncpy(task, name_start_doublequote, task_length);
      id[id_length] = '\0';
      task[task_length+1] = '\0';
      char* string = malloc((id_length + task_length+3) * sizeof(char));
      int stringSize = id_length + task_length+3;
      snprintf(string, id_length + task_length + 4, "[%s] %s", id, task);
      strncpy(pkmb1->KanMingBan[i][j], string, stringSize+1);
      pkmb1->KanMingBan[i][j][stringSize+1] = '\0';
      name_start_doublequote = strstr(name_end_doublequote + 1, "name\": \"");
      if(name_start_doublequote == NULL) {
        j++;
        free(id);
        free(task);
        break;
      }//end of file
      name_start_doublequote += 8;
      name_end_doublequote = strchr(name_start_doublequote + 1, '\"');
      id_start = strstr(id_end, "id\": ")+5;
      id_end = strchr(id_start, ',');
      id_length = id_end - id_start;
      task_length = name_end_doublequote - name_start_doublequote;
      j++;
      free(task);
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
  FILE *fptr = fopen("data/kmb.dat", "rb");
  struct kmb *pkmb1 = createKanMingBan(100, 3, 20);
  parseFileIntoKMB(fptr, pkmb1); 
  fclose(fptr);
  return *pkmb1;
}
