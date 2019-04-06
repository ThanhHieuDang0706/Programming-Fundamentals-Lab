#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
using namespace std;

double calculateSum(int n, int k, int option) {
    double sum = 0;

    for (int i = 1; i <= n; ++i) {
        sum += (double) 1/i;
    }
    
    cout << sum << endl;

    switch (option) {
        case 1: {
            sum = floor(sum * pow(10, k)) / pow(10, k);
            break;
        }
        case 2: {
            sum = round (sum * pow (10, k)) / pow(10, k);
            break;
        }
        case 3: {
            sum = ceil (sum);
        }
        case 4 : {
            sum = floor (sum);
        }
    }

    return sum;
}

int main () {
    cout << calculateSum(4, 2, 2) << endl;

    return 0;
}