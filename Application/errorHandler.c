#include <stdio.h>
#include <stdlib.h>
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

void checkParseError(void *ptr, const char *errorMessage) {
    if (ptr == NULL) {
        fprintf(stderr, "%s\n", errorMessage);
        exit(1); // Exiting automatically cleans up memory and closes files
    }
}

void checkBoundsError(void *start, void *end, const char *errorMessage) {
    if (end <= start) {
        fprintf(stderr, "%s\n", errorMessage);
        exit(1);
    }
}

void checkMathError(int value, const char *errorMessage) {
    if (value < 0) {
        fprintf(stderr, "%s\n", errorMessage);
        exit(1);
    }
}
