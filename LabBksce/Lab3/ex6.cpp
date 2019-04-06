#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <math.h>
using namespace std;

void printNumberOfSymmetricPairs(int numberOfElements, double arr[]) {
	/* Write code to calculate and print out the result to screen
	following the required format*/
    int count = 0;
    for (int i = 0; i < (numberOfElements / 2); ++i) {
        if (arr[i] == arr[numberOfElements - 1 -i])
            ++count;
    }
    cout << count;

}


int main () {
    double arr[] ={1, 2, 3, 4, 5, 3, 7, 1};
    printNumberOfSymmetricPairs(8, arr);


    return 0;
}