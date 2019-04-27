#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <math.h>
#include <cctype>
#define FILENAME "06007_sol.cpp"
using namespace std;

void revert(char* text, int fromPosition, int toPosition) {
    
    static int stop = (toPosition - fromPosition + 1) / 2 + fromPosition;
    if (fromPosition == stop) {
        return;
    } else {
        swap(text[fromPosition++], text[toPosition--]);
        revert(text, fromPosition, toPosition);
    }
}

void print_text(const char *const text, int n) {
    for (int i = 0; i < n; ++i){
        cout << text[i];
    }
    cout << endl;
}

int main () {
    char arr[] = "123456";
    revert(arr, 1, 4);
    print_text(arr, 6);
    return 0;
}