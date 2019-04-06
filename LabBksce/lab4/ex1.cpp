
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <math.h>
using namespace std;

/**
Print out the array 10x10 with option.
*/
void printArray(int option, int arr[10][10]){
    switch (option) {
        case 1: {
            for (int i = 0; i < 10; ++i) {
                for (int j = 0; j < 10; ++j) {
                    cout << arr[i][j];
                    if (i != 9 && j != 9) cout << ' ';
                }
            }
            break;
        }
        case 2 : {
            int sum = 0;
            for (int i = 0; i < 10; ++i) {
                for (int j = 0; j < 10; ++j) {
                    sum += arr[i][j];
                }
            }
            cout << sum;
            break;
        }
        case 3 : {
            for (int i = 0; i < 10; ++i) {
                int sum_column = 0;
                for (int j = 0; j < 0; ++j) {
                    sum_column += arr[j][i];
                }
                cout << sum_column;
                if (i != 9) cout << ' ';
            }
            break;
        }
        case 4 : {
            int sum_row_max = 0;
            int sum_row_max_index = 0;
            for (int i = 0; i < 10; ++i) {
                int sum_row = 0;
                for (int j = 0; j < 10; ++j) {
                    sum_row += arr[i][j];
                }
                if (i == 0) sum_row = sum_row_max;
                else {
                    if (sum_row > sum_row_max) {
                        sum_row_max = sum_row;
                        sum_row_max_index = i;
                    }
                }
            }
            cout << sum_row_max_index;
            break;
        }
    }



}