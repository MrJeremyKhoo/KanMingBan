#include <stdio.h>
#include "table.h"

void drawRowBorder(int cellWidth, int columns) {
    printf(" ");
    for (int i = 0; i < columns * (cellWidth + 2) + columns - 1; i++) {
        printf("-");
    }
    printf("\n");
}

void drawDataInRow(int cellWidth, char data[]) {
  printf("| %-*s ", cellWidth, data);

}

void drawTable(int rows, int columns, int cellWidth, char data[][ROWCHARSIZE]) {
    drawRowBorder(cellWidth, columns);
    int area = rows * columns;

    for (int i = 0; i < area; i++) {
      drawDataInRow(cellWidth, data[i]);

      if(i % columns == columns - 1) {
        printf("|\n");
        drawRowBorder(cellWidth, columns);
      }
    
    }
}

