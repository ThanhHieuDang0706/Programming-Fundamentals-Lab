#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <math.h>
#include <cctype>
#define FILENAME "05004_sol.cpp"
using namespace std;

void process(char* text, int p) {
    int count_unique_character[256] = {0}; // Ma ASCII: Ky tu in duoc

    for (int i = 0 ; i < strlen(text); ++i) {
        int tmp = (int)text[i];
        ++count_unique_character[tmp];
    }

    for (int i = 0; i < strlen(text); ++i) {
        int tmp = (int)text[i];
        if (count_unique_character[tmp] >= p) cout << text[i];
    }

}

int main () {
    char s[] = "aaaddwwers";
    process(s, 3);
    return 0;
}