#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <math.h>
using namespace std;

/* Write the code to calculate and print to screen */
void multipleMatrix(int mA, int nA, int** A, int mB, int nB, int** B) {
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
            if (j != 0) cout << ' ';
        }
        cout << endl;
    }
    
}