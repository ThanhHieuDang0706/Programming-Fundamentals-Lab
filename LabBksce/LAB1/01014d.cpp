#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstdlib>

using namespace std;

void getTextOfLessThan4DigitsNumber(int number){
     if (number < 100 || number > 999)
          return (void) -1;
     string text;
     int hang_don_vi = number % 10;
     int hang_tram = number / 100;
     int hang_chuc = number % 100 / 10;

     switch (hang_tram) {
          case 1: {
               text = "mot tram ";
               continue;
          }
          case 2: {
               text = "hai tram ";
               continue;
          }
          case 3: {
               text = "ba tram ";
               continue;
          }
          case 4: {
               text = "bon tram ";
               continue;
          }
          case 5: {
               text = "nam tram ";
               continue;
          }
          case 6: {
               text = "sau tram ";
               continue;
          }
          case 7: {
               text = "bay tram ";
               continue;
          }
          case 8: {
               text = "tam tram ";
               continue;
          }
          case 9: {
               text = "chin tram ";
               continue;
          }
     }

     switch (hang_chuc) {
          case 0: {
               text += "le ";
               continue;
          }
          case 1: {
               text += "mot muoi ";
               continue;
          }
          case 2: {
               text += "hai muoi ";
               continue;
          }
          case 3: {
               text += "ba muoi ";
               continue;
          }
          case 4: {
               text += "bon muoi ";
               continue;
          }
          case 5: {
               text += "nam muoi ";
               continue;
          }
          case 6: {
               text += "sau muoi ";
               continue;
          }
          case 7: {
               text += "bay muoi ";
               continue;
          }
          case 8: {
               text += "tam muoi ";
               continue;
          }
          case 9: {
               text += "chin muoi ";
               continue;
          }
     }

     switch (hang_don_vi) {
          case 1: {
               text += "mot";
               continue;
          }
          case 2: {
               text += "hai";
               continue;
          }
          case 3: {
               text += "ba";
               continue;
          }
          case 4: {
               text += "bon";
               continue;
          }
          case 5: {
               text += "lam";
               continue;
          }
          case 6: {
               text += "sau";
               continue;
          }
          case 7: {
               text += "bay";
               continue;
          }
          case 8: {
               text += "tam";
               continue;
          }
          case 9: {
               text += "chin";
               continue;
          }
     }

     cout << text << endl;
     return;


}

int main() {

     getTextOfLessThan4DigitsNumber(137);
     return 0;
}
