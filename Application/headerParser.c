#include "errorHandler.h"
#include "kmbInit.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parseHeaderToKmb(char** buffer, struct kmb *pkmb1 ) {
  char *b = *buffer;
  char *header_start = strstr(b, "\"HEADER\":");
  char *header_opening_bracket = strchr(header_start, '[');
  char *header_ending_bracket = strchr(header_start + 1, ']');
  char *start_doublequote = strchr(header_opening_bracket, '\"');
  char *end_doublequote = strchr(start_doublequote + 1, '\"');
  int task_length = end_doublequote - start_doublequote - 1;
  size_t i = 0;
  while(start_doublequote < header_ending_bracket) {
    strncpy(pkmb1->KanMingBan[i][0], start_doublequote+1, task_length);
    strncpy(pkmb1->Header[i], start_doublequote+1, task_length);
    pkmb1->KanMingBan[i][0][task_length] = '\0';
    pkmb1->Header[i][task_length] = '\0';
    start_doublequote = strchr(end_doublequote + 1, '\"');
    end_doublequote = strchr(start_doublequote + 1, '\"');
    task_length = end_doublequote - start_doublequote - 1;
    i++;
  }
  *buffer = header_ending_bracket;
  pkmb1->Header[i]=NULL;
}

void parseHeaderToArray(char* buffer, char*** array ) {
  char *b = buffer;
  char *header_start = strstr(b, "\"HEADER\":");
  char *header_opening_bracket = strchr(header_start, '[');
  char *header_ending_bracket = strchr(header_start + 1, ']');
  char *start_doublequote = strchr(header_opening_bracket, '\"');
  char *end_doublequote = strchr(start_doublequote + 1, '\"');
  int task_length = end_doublequote - start_doublequote - 1;
  size_t i = 0;
  while(start_doublequote < header_ending_bracket) {
    strncpy((*array)[i], start_doublequote+1, task_length);
    start_doublequote = strchr(end_doublequote + 1, '\"');
    end_doublequote = strchr(start_doublequote + 1, '\"');
    task_length = end_doublequote - start_doublequote - 1;
    i++;
  }
}

