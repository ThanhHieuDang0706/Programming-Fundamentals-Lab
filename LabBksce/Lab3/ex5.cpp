#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <math.h>
using namespace std;

void printNearest(double key, int numberOfElements, double arr[]) {
    double nearest = fabs(key - arr[0]);
    double result = arr[0];
    for (int i = 1; i < numberOfElements; ++i) {
        if (nearest > fabs(key - arr[i])){
            nearest = fabs(key - arr[i]);
            result = arr[i];
        }
    }
    cout << result;
}


int main () {
    double arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    printNearest(6.4, 9, arr);
    return 0;



}