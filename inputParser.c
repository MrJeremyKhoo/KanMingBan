#include "inputParser.h"

void openFile() {
      FILE *fptr = fopen("kmb.dat", "r");

    if (fptr == NULL) {
        printf("Error opening file!\n");
    }

    char line[256]; 
    while (fgets(line, sizeof(line), fptr) != NULL) {
        printf("%s", line); 
    }

    fclose(fptr); 
}
