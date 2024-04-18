#include "commandParser.h"
#include "../Application/add.h"
#include "../Application/delete.h"
#include "../Application/promote.h"
#include "../Application/dataParser.h"
#include "../Presentation/table.h"

void addCommand() {
  addTaskFile("{\"id\": 4, \"name\": \"this\", \"des\": \"Description for task4\"}", "Todo");
}

void deleteCommand() {
  deleteTaskFile("id\": 4,");
}

void promoteCommand() {
  promoteTaskFile("id\": 4,");
}


void command(char c) {
  char argChar = c;
  switch(argChar) {
    case add:
      addCommand();
      break;
    case del:
      deleteCommand();
      break;
    case promote:
      promoteCommand();
      break;
    case view:
  }
  drawTable(20, openFile());

}
