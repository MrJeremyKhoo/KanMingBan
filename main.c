#include "Presentation/table.h"
#include "Application/dataParser.h"
#include "Application/kmbInit.h"
#include "Business/commandParser.h"

typedef char*** ARRAY_OF_STRARRAY;
int main(int argc, char *argv[]) {
    int cellWidth = 20;
    //table: draw table
    //dataparser: openfile
    if(argc  >  1) {
      command(*argv[1]);
    }
    else {
      command('v');
    }
  
    // Print the number of command-line arguments
    printf("Number of arguments: %d\n", argc);

    // Print each command-line argument
    for (int i = 0; i < argc; i++) {
        printf("argv[%d] = %s\n", i, argv[i]);
    }

    return 0;
}

