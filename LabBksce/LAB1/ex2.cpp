#include <iostream>

using namespace std;

float convertTemperature(float temperature, int option, int isRound);

int main(){
     cout << convertTemperature (33.4123124215, 2, 1) << endl;
     cout << convertTemperature (34.123, 1, 0) << endl;


     return 0;
}

float convertTemperature (float temperature, int option, int isRound) {
     float result;

     switch (option) {
          case 1: {
               // Fahrenheit to Celcius
               result = (temperature - 32) * 5 / 9;
               break;
          }
          case 2: {
               // Celciu(s to Farenheit
               result = (temperature * 9 / 5) + 32;
               break;
          }
     }

     if (isRound) {
          // Round to two decimals
          result = roundf(result * 100) / 100;

     }

     return result;
}
