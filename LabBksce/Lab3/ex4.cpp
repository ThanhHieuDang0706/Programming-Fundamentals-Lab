#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <math.h>
using namespace std;

void printTotalLengthOfSignReversingSequence(int numberOfElements, int arr[]){
    int count = 0;
    for (int i = 1; i < numberOfElements - 1; ++i) {
        if (((arr[i] * arr[i - 1]) < 0) || (arr[i] * arr[i+1] < 0))
            ++count;
    }
    if (arr[0] * arr[1] < 0)
        ++count;
    if (arr[numberOfElements - 1] * arr[numberOfElements - 2] < 0)
        ++count;

    cout <<count;

}



int main () {
    int arr[] = {-1, 2, 3, -4, 5, -6, 7, 8};
    printTotalLengthOfSignReversingSequence(8, arr);
    return 0;
}

