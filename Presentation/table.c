#include <stdio.h>
#include "table.h"

void drawRowBorder(int cellWidth, int columns) {
    printf(" ");
    for (int i = 0; i < columns * (cellWidth + 2) + columns - 1; i++) {
        printf("-");
    }
    printf("\n");
}

void drawDataInRow(int cellWidth, char* kmb) {
  printf("| %-*s ", cellWidth, kmb);

}

void drawTable(int rows, int columns, int cellWidth, struct kmb kmb) {
    drawRowBorder(cellWidth, columns);
    int area = rows * columns;
    //check
  for (int j=0; j<4; j++) {
    for (int i = 0; i < 3; i++) {
      drawDataInRow(cellWidth, kmb.KanMingBan[i][j]);
      if(i % columns == columns - 1) {
        printf("|\n");
        drawRowBorder(cellWidth, columns);
      }
    
    }
  }

}

