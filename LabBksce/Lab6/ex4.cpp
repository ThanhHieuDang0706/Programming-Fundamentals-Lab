#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <math.h>
#include <cctype>
#define FILENAME "06007_sol.cpp"
using namespace std;


int recursiveMax(int *arr, int numberOfElements) {
    if (numberOfElements == 1) return arr[0];
    return max (arr[numberOfElements-1], recursiveMax(arr, numberOfElements - 1));
}

int main () {
    int arr[] = {1 ,4 ,6 ,2};
    cout << recursiveMax(arr, 4);

    return 0;
}