#ifndef COMMANDPARSER_H
#define COMMANDPARSER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum Command {
//add
  add ='a',
//regress
  regress ='r',
//delete
  del = 'd',
//swap
  swap = 's',

	view = 'v',

	promote = 'f',
};
void command(char c, char* id);

#endif
