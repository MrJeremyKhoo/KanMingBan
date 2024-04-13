#include "Presentation/table.h"
#include "Application/dataParser.h"
#include "Application/kmbInit.h"
typedef char*** ARRAY_OF_STRARRAY;
int main() {
    // Example usage
//    char data[][100] = {
//        "Todo", "T1", "T2",
//        "Progress", "Value2", "Value3",
//        "Done", "Value5", "Value6"
//    };

    //int rows = 3;
    //int columns = 3;
    int cellWidth = 20;
    //table.h
    //dataparser openfile
    drawTable(3, 3, cellWidth, openFile());

    return 0;
}

