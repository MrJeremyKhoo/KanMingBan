#include "errorHandler.h"
#include "add.h"
#include "../global.h"
#include "delete.h"
#include "headerParser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void promoteTaskFile(char* id) {
    char filename[256]; // Adjust the size as per your needs
    snprintf(filename, sizeof(filename), "%s/%s", program_directory, "data/kmb.dat");
    FILE *fptr = fopen(filename, "rb+");
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
    // Create new buffer with enough space for the new task and null terminator
    int taskLen2 =  lastClosingBracket - strchr(openingClosingBracket, '{') + 1;
    char * task = malloc(taskLen2 * sizeof(char));
    memcpy(task, strchr(openingClosingBracket,'{'), taskLen2);
    task[taskLen2] = '\0';

    deleteTaskFile(id);
    addTaskFile(task, promotionHeader);
	return;
}
