#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <math.h>
#include <cctype>
#define FILENAME "05002_sol.cpp"
using namespace std;

/* Please note that your code must not contain any of words in
 {"include"}; */

//---------------------------------------------------------
// Begin implementation
//---------------------------------------------------------
void process_minus (const char * inputText, int &i) {
    int nochange = i;
    int tmp;
    bool negative = false;
    if (inputText[i] == '-') {
        if (isdigit(inputText[i+1])) 
                tmp = i + 1;
            
        while (isdigit(inputText[tmp]) && tmp < strlen(inputText)) { // Check the case when -000000000 (non-negative number)
            if (inputText[tmp] == '0') ++tmp;
            else 
            {
                negative = true;
                break;
            }
        }

        if (negative) {
            while(isdigit(inputText[tmp]) && tmp < strlen(inputText)) {
                ++tmp;
            }
            i = tmp;
        } 
    }
    
    if (i == nochange) {
        ++i;
        process_minus(inputText, i);
    }
    else if (inputText[i] == '-') process_minus(inputText, i);
    else return;


}
 
void process(char* inputText) {
    
    int i = 0;
    while (i < strlen(inputText)) {
        bool negative = false;
        int tmp;
        int nochange = i;

        if (inputText[i] == '-') {
            if (isdigit(inputText[i+1])) {
                tmp = i + 1;
            }

            while (isdigit(inputText[tmp])) {
                if (inputText[tmp] == '0') ++tmp;
                else {
                    negative = true;
                    break;
                }
            }
        
            if (negative) {
                while (isdigit(inputText[tmp])) ++tmp;
                i = tmp;
            }

        }
        if (i == nochange) {
            cout << inputText[i++];
        }
        else {
            if (inputText[i] == '-') continue;
        }
        
    }
}

int main () {
    char s1[] = "-003214ags-2000d--vgad-f-000fad-vitdas---2-325";
    
    process(s1);

    return 0;
}
