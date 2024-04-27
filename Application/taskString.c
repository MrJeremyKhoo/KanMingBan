#include <stdio.h>
#include <stdlib.h>

char* taskStr (int id, char* str) {
  // todo: fit the description
  // get the total size
  int size = snprintf(NULL, 0, "{\"id\": %d, \"name\": \"%s\", \"des\": \"Description for task4\"}", id, str);
  char *taskStr = malloc(size * sizeof(char) + 1);
  snprintf(taskStr, size+1, "{\"id\": %d, \"name\": \"%s\", \"des\": \"Description for task4\"}", id, str);
  return taskStr;
}

