#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <math.h>
using namespace std;

/* Write the code to calculate and print to screen */
void multipleMatrix(int mA, int nA, int A[2][2], int mB, int nB, int B[2][2]) {
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
        cout << endl;
    }
    
}

int main () {
    int a[2][2] = {
        {2, 1},
        {3, 4}
    };
    int b[2][2] = {
        {3,1},
        {1, 1}
    };
    multipleMatrix(2, 2, a, 2, 2, b);
    return 0;
}