#include "commandParser.h"
#include "../Application/add.h"
#include "../Application/dataParser.h"
#include "../Presentation/table.h"

//todo: implment add task
void addCommand() {
  addTaskFile("this", "Todo");
}

void command(char c) {
  char argChar = c;
  switch(argChar) {
    case add:
      addCommand();
    case view:
      break;
  }

  drawTable(20, openFile());
}
