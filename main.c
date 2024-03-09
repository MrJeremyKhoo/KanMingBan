#include "table.h"

int main() {
    // Example usage
    char data[][100] = {
        "Header1", "Header2", "Header3",
        "Value1", "Value2", "Value3",
        "Value4", "Value5", "Value6"
    };

    int rows = 3;
    int columns = 3;
    int cellWidth = 20;

    drawTable(rows, columns, cellWidth, data);

    return 0;
}

