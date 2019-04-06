#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(){
    double a = 1058.141507549912;
    cout << a * a << endl;
    double b = 807.6, c = 683.7;
    cout << b * b + c * c << endl;
    if (a * a == b * b + c * c) 
        cout << "This is equal" << endl;
    else cout << "Not equal" << endl;
    cout << "a * a - (b* b + c * c) = " << a * a -(b * b + c* c) << endl; 
    if (a * a -(b * b + c* c) < 0.01) 
        cout << "Right";
    return 0;
}