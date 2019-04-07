#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <math.h>
using namespace std;

/* Write the code to calculate and print to screen */
void multipleMatrix(int mA, int nA, int A[4][5], int mB, int nB, int B[5][3]) {
    if (nA != mB) {
        cout << "-1";
        return;
    }
    int mutiply_matrix[mA][nB];
    for (int i = 0; i < mA; ++i) {          
        for (int j = 0; j < nB; ++j) {
            mutiply_matrix[i][j] = 0;
            for (int k = 0; k < mB; ++k) {
                mutiply_matrix[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    for (int i = 0; i < mA; ++i) {
        for (int j = 0; j < nB; ++j) {
            cout << mutiply_matrix[i][j];
            if (j != (nB - 1)) cout << ' ';
        }
        if (i != (mA - 1)) cout << endl;
    }
    
}

int main () {
    int a[4][5] = {
        {1,2,3,4,5},
        {2,3,4,5,6},
        {3,4,5,6,7},
        {4,5,6,7,8}
    };
    int b[5][3] = {
        {8,6,7},
        {7,3,5},
        {1,9,5},
        {3,4,6},
        {2,1,9}
    };
    multipleMatrix(4, 5, a, 5, 3, b);
    return 0;
}