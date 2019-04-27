#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <math.h>
#include <cctype>
#define FILENAME "06007_sol.cpp"
using namespace std;

void swap (int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}


void recursiveReverse(int* arr, int numberOfElements) {
    static int stop_condition = numberOfElements / 2;
    static int count = 0;
    static int original_numberOfElements = numberOfElements;

    if (count == stop_condition) return;

    else {
        swap(arr[count++], arr[numberOfElements-1]);
        recursiveReverse(arr, numberOfElements - 1);
    }
    
}

void print_array(const int *const arr, int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

int main () {
    // int arr[] = {1,2,3,4,5};
    // recursiveReverse(arr, 5);
    // print_array(arr, 5);
    int arr2[] = {1, 2, 3, 4, 5, 6,7};
    recursiveReverse(arr2, 7);
    print_array(arr2, 7);
    return 0;
}