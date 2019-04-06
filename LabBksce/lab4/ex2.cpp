#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <math.h>
using namespace std;

/* Given arr is an matrix of 5x5, write the code to find the number
of number 1 in rows and columns and then print to the screen following
the required format as in the exercise description.*/
void findTheMostNumberOfOneInMatrix(bool arr[5][5]) {
    int row_index = 0, column_index = 0;
    int row_max = 0, column_max = 0;
    for (int i = 0; i < 5; ++i) {
        int row_count = 0;
        int column_count = 0;
        for (int j = 0; j < 5; ++j) {
            if (arr[i][j] == 1) ++row_count;
            if (arr[j][i] == 1) ++column_count;
        }
        if (i == 0) {
            row_max = row_count;
            column_max = column_count;
        } else {
            if (row_max < row_count) {
                row_max = row_count;
                row_index = i;
            }
            if (column_max < column_count) {
                column_max = column_count;
                column_index = i;
            }
        }
    }
    cout << "Row index: " << row_index << endl;
    cout << "Column index: " << column_index;

}

int main () {
    return 0;
}