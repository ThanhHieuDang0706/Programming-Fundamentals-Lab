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
               continue;
          case 2:
               cout << a - b << endl;
               continue;
          case 3:
               cout << a * b << endl;
               continue;
          case 4:
               if (b == 0) {
                    cout << "Do not divided " << a << " by zero!" << endl;
                    continue;
               } else {
                    cout << (float) a / b << endl;
                    continue;
               }
          case 5:
               cout << a*a + b*b << endl;
               continue;
     }
}
