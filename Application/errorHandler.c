#include "errorHandler.h"

void catchFileError(FILE *fptr) {
  if (fptr == NULL) {
    printf("File does not exist. Creating a new file.\n");
    fptr = fopen("kmb.dat", "w"); // Opening in write mode to create the file
    if (fptr == NULL) {
      printf("Error creating file!\n");
      return;
    }
  }
}

void checkCharPointer(char *buffer) {
  if (buffer == NULL) {
      fprintf(stderr, "Memory allocation failed\n");
      exit(1);
    }
}

void checkFileSize(size_t bytesRead, long int fileSize) {
  if ((long int) bytesRead != fileSize) {
      fprintf(stderr, "Error reading file\n");
      exit(1);
  }
}
