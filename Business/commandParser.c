#include "commandParser.h"
#include "../Application/add.h"
#include "../Application/dataParser.h"
#include "../Presentation/table.h"

//todo: implment add task
void addCommand() {
  addTaskFile("{\"id\": 4, \"name\": \"this\", \"des\": \"Description for task4\"}", "Todo");
}

void command(char c) {
  char argChar = c;
  switch(argChar) {
    case add:
      addCommand();
      break;
    case view:
  }
  drawTable(20, openFile());

}
