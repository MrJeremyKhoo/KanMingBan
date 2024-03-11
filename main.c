#include "table.h"
#include "inputParser.h"

int main() {
    // Example usage
    char data[][100] = {
        "Todo", "T1", "T2",
        "Progress", "Value2", "Value3",
        "Done", "Value5", "Value6"
    };

    int rows = 3;
    int columns = 3;
    int cellWidth = 20;
    openFile();
    drawTable(rows, columns, cellWidth, data);

    return 0;
}

