#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <math.h>
#include <cctype>
#define FILENAME "06000_sol.cpp"
using namespace std;


void process (int n) {
    static int count = 1;
    if (n != 0) {
        cout << count++ << ' ';
        process(n-1);
    }
}


int main () {
    process(55);
    return 0;
}

