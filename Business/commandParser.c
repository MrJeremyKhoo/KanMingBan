#include "commandParser.h"
#include "../Application/add.h"
#include "../Application/delete.h"
#include "../Application/promote.h"
#include "../Application/regress.h"
#include "../Application/dataParser.h"
#include "../Application/availID.h"
#include "../Application/makeAvailID.h"
#include "../Application/taskString.h"
#include "../Presentation/table.h"

void addCommand(char* str) {
  int availId = availID();
  addTaskFile(taskStr(availId,str), "Todo");
}

void deleteCommand(char* id) {
  if (id != NULL && id != 0x0) {
    int length = strlen(id) + 7; // length of "id\": ", the length of v, and the comma
    char* result = (char*)malloc((length + 1) * sizeof(char)); // +1 for null terminator
    snprintf(result, length + 1, "id\": %s,", id);
    deleteTaskFile(result);
    makeAvailID(atoi(id));
    return;
  }
  printf("Did not specify which task(ID) to delete\n");
}

void promoteCommand(char* id) {
  if (id != NULL && id != 0x0) {
    int length = strlen(id) + 7; // length of "id\": ", the length of v, and the comma
    char* result = (char*)malloc((length + 1) * sizeof(char)); // +1 for null terminator
    snprintf(result, length + 1, "id\": %s,", id);
    promoteTaskFile(result);
    return;
  }
  printf("Did not specify which task(ID) to promote\n");
}

void regressCommand(char* id) {
  if (id != NULL && id != 0x0) {
    int length = strlen(id) + 7; // length of "id\": ", the length of v, and the comma
    char* result = (char*)malloc((length + 1) * sizeof(char)); // +1 for null terminator
    snprintf(result, length + 1, "id\": %s,", id);
    regressTaskFile(result);
    return;
  }
  printf("Did not specify which task(ID) to regress\n");
}

void swapCommand() {
  makeAvailID(3);
}

void command(char c, char* arg1) {
  char argChar = c;
  switch(argChar) {
    case add:
      addCommand(arg1);
      break;
    case del:
      deleteCommand(arg1);
      break;
    case promote:
      promoteCommand(arg1);
      break;
    case regress:
      regressCommand(arg1);
      break;
    case swap:
      swapCommand();
      break;
    case view:
  }
  //todo: cannot be fixed value for column width
  drawTable(20, openFile());

}
