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
    // Print the top border
    drawRowBorder(cellWidth, columns);

    // Print the table contentt
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < columns; j++) {
        drawDataInRow(cellWidth, data[j * columns + i]);
      }
      printf("|\n");
      drawRowBorder(cellWidth, columns);
    }
}

