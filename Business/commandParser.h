#ifndef COMMANDPARSER_H
#define COMMANDPARSER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum Command {
//add
  a,
//regress
  r,
//delete
  d,
//swap
  s,
};
void command(char* c);

void addCommand(enum Command c);

#endif
