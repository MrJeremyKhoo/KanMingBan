#include "commandParser.h"
#include "../Application/add.h"
#include "../Application/delete.h"
#include "../Application/promote.h"
#include "../Application/dataParser.h"
#include "../Presentation/table.h"

void addCommand() {
  addTaskFile("{\"id\": 4, \"name\": \"this\", \"des\": \"Description for task4\"}", "Todo");
}

void deleteCommand(char* id) {
  if (id != NULL) {
    int length = strlen(id) + 7; // length of "id\": ", the length of v, and the comma
    char* result = (char*)malloc((length + 1) * sizeof(char)); // +1 for null terminator
    snprintf(result, length + 1, "id\": %s,", id);
    deleteTaskFile(result);
    return;
  }
  printf("Did not specify which task(ID) to delete\n");
}

void promoteCommand(char* id) {
  if (id != NULL) {
    int length = strlen(id) + 7; // length of "id\": ", the length of v, and the comma
    char* result = (char*)malloc((length + 1) * sizeof(char)); // +1 for null terminator
    snprintf(result, length + 1, "id\": %s,", id);
    promoteTaskFile(result);
    return;
  }
  printf("Did not specify which task(ID) to promote\n");
}

void command(char c, char* id) {
  char argChar = c;
  switch(argChar) {
    case add:
      addCommand();
      break;
    case del:
      deleteCommand(id);
      break;
    case promote:
      promoteCommand(id);
      break;
    case view:
  }
  drawTable(15, openFile());

}
