#include <stdio.h>
#include "table.h"
#include "../Application/kmbInit.h"

void drawRowBorder(int cellWidth, int columns) {
    printf(" ");
    for (int i = 0; i < columns * (cellWidth + 2) + columns - 1; i++) {
        printf("_");
    }
    printf("\n");
}

void drawTopRowBorder(int cellWidth, int columns) { //put your inpiraitonal quote here
    printf(" \"But they layed bricks everyday...\"");
    for (int i = 36; i < columns * (cellWidth + 2) + columns - 1; i++) {
        printf("_");
    }
    printf("\n");
}

void drawDataInRow(int cellWidth, char* kmb) {
  printf("| %-*s ", cellWidth, kmb);

}

void drawTable(int cellWidth, struct kmb * kmbptr) {
  struct kmb kmb = *kmbptr;
  int columns = kmb.column;
  int rows = kmb.row;
    drawRowBorder(cellWidth, columns);
    //check:warn("%s");
  for (int j=0; j<rows; j++) {
    for (int i = 0; i < columns; i++) {
      drawDataInRow(cellWidth, kmb.KanMingBan[i][j]);
      if(i % columns == columns - 1) {
        printf("|\n");
        drawRowBorder(cellWidth, columns);
      }
    
    }
  }
  freeKanMingBan(kmbptr, columns, rows);

}

