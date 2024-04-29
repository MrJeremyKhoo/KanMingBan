#ifndef COMMANDPARSER_H
#define COMMANDPARSER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum Command {
	add ='a',
	regress ='r',
	del = 'd',
	swap = 's',
	view = 'v',
	promote = 'f',
};
void command(char c, char* id);

#endif
