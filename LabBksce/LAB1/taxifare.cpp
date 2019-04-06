#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
using namespace std;

float calculateTaxiFare(float distance) {
    float money;
    if (distance <= 10)
        money = 10000 * distance;
    else if (distance > 10 && distance <= 30) 
        money = 10000 * 10 + 6000 * (distance - 10);
    else if (distance > 30)
        money = 10000 * 10 + 6000 * 20 + (distance - 30) * 4000;
    
    return money;
}

int main () {
    cout << "Compiled success.";
    cout << endl;
    return 0;
}