#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <math.h>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void printNumberOfCoprimeNumber(int numberOfElements, int arr[]){
    int count = 0;
    for (int i = 1; i < numberOfElements - 1; ++i) {
        if ((gcd(arr[i], arr[i+1]) == 1) || (gcd(arr[i], arr[i-1]) == 1))
            ++count;
    }
    if (gcd(arr[0], arr[1]) == 1)
        ++count;
    if (gcd(arr[numberOfElements - 1], arr[numberOfElements - 2]) == 1)
        ++count;
    cout << count;

}

int main () {
    int arr[] = {30191,18007, 11337, 15467, 12287, 27753, 10383};
    printNumberOfCoprimeNumber(7,arr);
    cout << endl << gcd(10383,27753) << endl;
    return 0;
}