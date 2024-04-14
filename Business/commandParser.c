#include "commandParser.h"

//todo: implment add task
void addCommand(enum Command c) {
 printf("add task");
}

void command(char* c) {
  enum Command com;
  if (*c == 'a') {
    com = a;
    addCommand (com);
  }
}
