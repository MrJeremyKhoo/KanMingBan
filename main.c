#include "Presentation/table.h"
#include "Application/dataParser.h"
#include "Application/kmbInit.h"
#include "Business/commandParser.h"
#include "./global.h"
#include <unistd.h>

const char *program_directory;

typedef char*** ARRAY_OF_STRARRAY;
int main(int argc, char *argv[]) {
      char path[1024];
    ssize_t len = readlink("/proc/self/exe", path, sizeof(path) - 1);
    if (len != -1) {
        path[len] = '\0';
        char *last_slash = strrchr(path, '/');
        *last_slash = '\0'; // Replace the last '/' with '\0' to get the directory path
        program_directory = path;
    } else {
        perror("readlink");
    }

  //table: draw table
  //dataparser: openfile
  //todo: does not check size of char param
  if(argc  ==  3) {
    if(argv[1] == NULL) {
      command('v', "0");
    } else {
    command(*argv[1], argv[2]);
    }
  }
  else if (argc == 2){
    command(*argv[1], 0x0);
  }
      command('v', "0");
//  // Print the number of command-line arguments
//    printf("Number of arguments: %d\n", argc);
//
//    // Print each command-line argument
//    for (int i = 0; i < argc; i++) {
//        printf("argv[%d] = %s\n", i, argv[i]);
//    }
//
    return 0;
}

