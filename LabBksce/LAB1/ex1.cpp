#include <iostream>
#include <cmath>

using namespace std;

void print_number(float number, int option);

int main() {


     print_number(12.56734, 4);
     print_number(-63.635, 4);
     print_number(-62.1235, 4);


     return 0;

}

void print_number (float number, int option) {
     switch (option) {
          case 1: {
               cout << round(number) << endl;
               continue;
          }
          case 2: {
               number = ceil(number);
               cout << number << endl;
               continue;
          }
          case 3: {
               cout <<  floor(number) << endl;
               continue;
          }
          case 4: {
               number = roundf(number * 100) / 100;
               cout << number << endl;
               continue;
          }

     }


     return;
}
