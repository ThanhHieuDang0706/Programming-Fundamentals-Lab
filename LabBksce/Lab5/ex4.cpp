#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <math.h>
#include <cctype>
#define FILENAME "05007_sol.cpp"
using namespace std;

void lower_all_text(char* text) { //for ease to process
    for (int i = 0; i < strlen(text); ++i) {
        if (isupper(text[i])) {
            text[i] = text[i] + 32;
        }
    }
}


void process(char* text, char** priText, int numberOfPriText) {
    lower_all_text(text);
    text[0] -= 32;
    




}

int main () {



    return 0;
}
