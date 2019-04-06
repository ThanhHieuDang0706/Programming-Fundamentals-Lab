#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <math.h>
using namespace std;

void minMax(int option, int numberOfElements, int arr[]){
    switch(option){
        case 1: { //min
            int min = arr[0];
            for (int i = 1; i < numberOfElements ; ++i) {
                if (min > arr[i])
                    min = arr[i];
            }
            cout << "min is " << min;
            break;
        }
        case 2: {//max
            int max = arr[0];
            for (int i = 1; i < numberOfElements; ++i) {
                if (arr[i] > max)
                    max = arr[i];
            }
            cout << "max is " << max;           
            break;
        }
        case 3: {
            int min = arr[0];
            for (int i = 0; i < numberOfElements; ++i) {
                if (min > arr[i])
                    min = arr[i];
            }          
            int max = arr[0];
            for (int i = 1; i < numberOfElements; ++i) {
                if (arr[i] > max)
                    max = arr[i];
            }
            cout << "min is " << min << '\n'
                 << "max is " << max;    
            break;
        }
    }




}


int main () {
    int arr[] = {
        12053, 16962, 3584, 29734, 6654, 16972, 21457, 14369, 22532, 2963 ,2607, 2483, 911 ,11635, 10067, 22848 ,4675, 12938, 2223 ,22142, 23754, 6511, 22741, 20175, 21459 ,17825 ,3221 ,17870 ,1626 ,31934, 15205 ,31783};
    cout << sizeof(arr) / sizeof(arr[0]) << endl;
    minMax(2, 32, arr);
    cout << endl;
    return 0;
}
