#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <math.h>
#include <cctype>
#define FILENAME "06000_sol.cpp"
using namespace std;

int reSum (int n) {
    static int count = 1;
    if (n >= 1) {
        return count++ + reSum(n-1);
    } else {
        return 0;
    }
}

int main () {
    cout << reSum(74);
    return 0;
}