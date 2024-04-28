#include "errorHandler.h"
#include "add.h"
#include "delete.h"
#include "headerParser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void promoteTaskFile(char* id) {
    FILE *fptr = fopen("data/kmb.dat", "rb+");
    if (fptr == NULL) {
        perror("Error opening file");
        return;
    }

    // Determine the size of the file
    fseek(fptr, 0, SEEK_END);
    long int fileSize = ftell(fptr);
    fseek(fptr, 0, SEEK_SET);

    // Allocate memory dynamically for the file content
    char *buffer = (char *)malloc(fileSize + 1); // +1 for null terminator
		checkCharPointer(buffer);
    size_t bytesRead = fread(buffer, 1, fileSize, fptr);
		checkFileSize(bytesRead, fileSize);
    buffer[fileSize] = '\0'; // Null-terminate the string
  
  
    char *promotionHeader = NULL;
    char *lastClosingBracket = NULL;
    char *taskHeader = NULL;

    char* idplace = strstr(buffer, id);

    //todo: change this to not just be 100 hardcoded
    //findHeader
    char ** headerArray = calloc(10, sizeof(char*));
    //find task's header
    for(int i = 0; i < 3; i++) {
      headerArray[i] = (char*)calloc(100, sizeof(char));
    }
    parseHeaderToArray(buffer, &headerArray);
    //determine header of id
    char *header_start = strstr(buffer, "\"HEADER\":");
    char *header_opening_bracket = strchr(header_start, '[');
    char *header_ending_bracket = strchr(header_start + 1, ']');
  //todo:add more headers
    for (int i = 0; i < 3; ++i) {
      taskHeader = strstr(header_ending_bracket, headerArray[i]);
      if (taskHeader > idplace) {
        promotionHeader = headerArray[i];
        break;
      }
    }
    if(promotionHeader == NULL) {
      return;
    }
    //delete task
    char* openingClosingBracket = strreversechar(idplace, ',');
    char* firstSquareBracket = strreversechar(idplace, '[');
    if(openingClosingBracket < firstSquareBracket) {
      openingClosingBracket = firstSquareBracket + 1;
    }
    lastClosingBracket = strchr(openingClosingBracket, '}');
    // Calculate the position to insert the task
    int position = openingClosingBracket - buffer;
    // Create new buffer with enough space for the new task and null terminator
    int taskLen =  lastClosingBracket - openingClosingBracket;
    int taskLen2 =  lastClosingBracket - strchr(openingClosingBracket, '{') + 1;
    char * task = malloc(taskLen2 * sizeof(char));
    memcpy(task, strchr(openingClosingBracket,'{'), taskLen2);
    task[taskLen2] = '\0';
    int newSize = fileSize - taskLen;
    char *newBuffer = (char *)malloc(newSize);

    deleteTaskFile(id);
    addTaskFile(task, promotionHeader);
	return;
}
