#include <iostream>
#include <string>

using namespace std;


bool isPrimeNumber(int num) {
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false;
    for (int i = 3; i < num/2; i+=2) {
        if (num % i == 0) return false;
    }
    return true;
}

int Fibonacci(int num) {
    if (num == 0) return 0;
    else if (num == 1 || num == 2) return 1;
    else {
        return Fibonacci(num-1) + Fibonacci(num-2);
    }
}

int main () {
    // cout << Fibonacci(2) << endl;
    // cout << Fibonacci(3) << endl;
    // cout << Fibonacci(12) << endl;
    // cout << Fibonacci(10) << endl;
    // int m = 20;
    // m = (0 < 1) ? 2*2 : (m*2);
    // cout << m << endl;
    // cout << Fibonacci(15) << endl;

    // cout << "-----------------" << endl;
    // char s1[] = R"(\he\qwegd)";
    // cout << s1 << endl;
    string s[2];
    s[1] = "Hello World";
    cout << s[1];
    return 0;
}