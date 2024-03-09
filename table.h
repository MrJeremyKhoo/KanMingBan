#ifndef TABLE_H
#define TABLE_H
#define ROWCHARSIZE 100
#define RED_TEXT "\033[1;31m"

void drawTable(int rows, int columns, int cellWidth, char data[][ROWCHARSIZE]);

#endif // MYHEADER_H
