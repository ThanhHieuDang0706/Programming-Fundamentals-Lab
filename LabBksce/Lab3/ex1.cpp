#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <math.h>
using namespace std;

void printNumberOfMaximaAndMinima(int numberOfElements, int arr[]){
    int count_max = 0;
    int count_min = 0;
    if (arr[0] > arr[1])
        ++count_max;
    else if (arr[0] < arr[1])
        ++count_min;

    if (arr[numberOfElements-1] > arr[numberOfElements-2])
        ++count_max;
    else if (arr[numberOfElements-1] < arr[numberOfElements-2])
        ++count_min;

    for (int i = 1; i < (numberOfElements - 1); ++i) {
        if (arr[i] < arr[i+1] && arr[i] < arr[i-1])
            ++count_min;
        if (arr[i] > arr[i+1] && arr[i] > arr[i-1])
            ++count_max;
    }

    cout << count_max + count_min;
}

int main () {
    int arr[] = {1, 2, 0, 3, 4, 5, 6, 8, 9, 0};

    printNumberOfMaximaAndMinima(10, arr);
    return 0;
}