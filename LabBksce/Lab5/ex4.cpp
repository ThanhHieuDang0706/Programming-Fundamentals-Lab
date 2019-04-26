#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <math.h>
#include <cctype>
#define FILENAME "05007_sol.cpp"
using namespace std;

void lower_all_text(char*);
void upper_pritext(char*, char*);

void lower_all_text(char* text) { 
    for (int i = 0; i < strlen(text); ++i) {
        if (isupper(text[i])) {
            text[i] += 32;
        }
    }
}

void upper_pritext (char*text, char* pritext) {
    int len = strlen(pritext);
    char tmp[len];
    strcpy(tmp, pritext);
    lower_all_text(tmp);
    int n = 0, m = 0;
    int times = 0;
    int pattern_position[128] = {0};

    // Find pattern position
    while (text[n] != '\0') {
        if (text[n] == tmp[m]) {
            
            while (text[n] == tmp[m] && text[n] != '\0'){
                ++n;
                ++m;
            }

            if (m == len) {
                pattern_position[times++] = n - len;
            }
        }

        else {
            while(text[n] != ' ') {
                ++n;
                if (text[n] == '\0') continue;
            }
        }
        ++n;
        m = 0;
    }

    for (int i = 0 ; i < times; ++i) {
        int tmp_index = 0;
        for (int j = pattern_position[i]; j < len + pattern_position[i]; ++j) {
            if (isupper(pritext[tmp_index++])) {
                if (islower(text[j])) text[j] -= 32;
            } 
        }
    }
}


void process(char* text, char[1][16] priText ,  int numberOfPriText) {
    lower_all_text(text);

    for (int i = 0; i < numberOfPriText; ++i) {
        upper_pritext(text, priText[i]);
    }

    int index = 0;
    while (!isalpha(text[index])) ++index;
    if (islower(text[index])) text[index] -= 32;
    ++index;

    for ( ;text[index] != '\0'; ++index) {
        if (text[index] == '.' || text[index] == ':' || text[index] == '?' || text[index] == '!') {
            ++index;

            while(!isalpha(text[index]) && !isdigit(text[index])) ++index;

            if (islower(text[index])) text[index] -= 32;
        }
    }

    cout << text;
}

int main () {
    char s1[] = " nghe BI thu tinh uy KieN Giang NguyEn ThaNh Nghi Bao cao tinh hInh thuc hien nhiem vu tu sau DaI hoi Dang bo tinH den nay. 14/12, toi da giet nguoi.";
    char pritext[1][16] = {"TP.HCM"};
    process(s1, pritext, 1);
    return 0;
}
