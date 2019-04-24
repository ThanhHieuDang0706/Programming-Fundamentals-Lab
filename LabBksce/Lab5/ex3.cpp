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

/* Write the code to print to screen the longest common substring*/
void getLongestCommonSubstring(char* str1, char* str2) 
{
    int T[strlen(str1) + 1][strlen(str2) + 1] = {0, 0};

    for (int i = 0; i < strlen(str1) + 1; ++i) {
        for (int j = 0; j < strlen(str2) + 1; ++j) {
            T[i][j] = 0;
        }
    }

    int position_of_largest_substring[2] = {0};

    int max_len_of_substring = 0;

    for (int i = 1; i <= strlen(str1); ++i) {
        for (int j = 1; j <= strlen(str2); ++j) {
            if (str1[i-1] == str2[j-1]){
                T[i][j] = T[i-1][j-1] + 1;
                if (max_len_of_substring < T[i][j]) {
                    max_len_of_substring = T[i][j];
                    position_of_largest_substring[0] = i - 1;
                    position_of_largest_substring[1] = j - 1;
                }
            }
        }
    }
    
    
    int start = position_of_largest_substring[0] + 1 - max_len_of_substring;
    for (; start < position_of_largest_substring[0] + 1; ++start) {
        cout << str1[start];
    }

}

int main () {
    char s1[] = "aabaadefggh";
    char s2[] = "dllmaadeikl";
    getLongestCommonSubstring(s1,s2);

    return 0;
}