#include <iostream>
#include <cmath>

using namespace std;

void calculateAndPrintResult(int a, int b, int option);

int main() {
     calculateAndPrintResult(1, 0, 4);

}

void calculateAndPrintResult(int a, int b, int option){
     switch (option) {
          case 1:
               cout << a + b << endl;
               break;
          case 2:
               cout << a - b << endl;
               break;
          case 3:
               cout << a * b << endl;
               break;
          case 4:
               if (b == 0) {
                    cout << "Do not divided " << a << " by zero!" << endl;
                    break;
               } else {
                    cout << (float) a / b << endl;
                    break;
               }
          case 5:
               cout << a*a + b*b << endl;
               break;
     }
}
