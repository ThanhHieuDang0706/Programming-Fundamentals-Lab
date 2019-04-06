#include <iostream>

using namespace std;

int getElement (int a, int b, int c, int d, int e, int option, int K = 0){
     int arr [] = {a, b, c, d, e};

     switch (option) {
          case 1:{
               int max = arr[0];
               for (int i = 1; i < 5; ++i) {
                    if (max < arr[i])
                         max = arr[i];
               }
               return max;
               break;
          }
          case 2:{
               int min = arr[0];
               for (int i = 1; i < 5; ++i) {
                    if (min > arr[i])
                         min = arr[i];
               }
               return min;
               break;
          }
          case 3:{
               for (int i = 0; i < 5; ++i){
                    for (int j = i + 1; j < 5; ++j){
                         if (arr[i] > arr[j]) {
                              int temp = arr[i];
                              arr[i] = arr[j];
                              arr[j] = temp;
                         }
                    }
               }
               return arr[2];
               break;
          }
          case 5:{
               cout << "Nhap so nguyen K : ";
               cin >> K;
               int d[5];
               for (int i = 0; i < 5; ++i){
                    d[i] = arr[i] - K;
               }

               int max = d[0];
               for (int i = 1; i < 5; ++i) {
                    if (max < d[i])
                         max = d[i];
               }

               for (int i = 0; i < 5 ; ++i) {
                    if (d[i] == max)
                         return arr[i];
               }
               break;
          }
          case 4:{
               cout << "Nhap so nguyen K : ";
               cin >> K;
               int d[5];
               for (int i = 0; i < 5; ++i){
                    d[i] = arr[i] - K;
               }

               int min = d[0];
               for (int i = 1; i < 5; ++i) {
                    if (min > d[i])
                         min = d[i];
                    }

               for (int i = 0; i < 5 ; ++i) {
                    if (d[i] == min)
                         return arr[i];
               }
               break;
          }

     }
}

int main() {
     int num = getElement(2,6, -5, 10, 7, 5);
     cout << num << endl;



     return 0;
}
