#include <stdio.h>
#include "table.h"

void drawTable(int rows, int columns, int cellWidth, char data[][ROWCHARSIZE]) {
    // Print the top border
    for (int i = 0; i < columns * (cellWidth + 1) + 1; i++) {
        printf("-");
    }
    printf("\n");

    // Print the table content
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("| %-*s ", cellWidth, data[i * columns + j]);
        }
        printf("|\n");

        // Print the row separator
        for (int k = 0; k < columns * (cellWidth + 1) + 1; k++) {
            printf("-");
        }
        printf("\n");
    }
}


