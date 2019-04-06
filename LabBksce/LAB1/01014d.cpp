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
               break;
          }
          case 2: {
               text = "hai tram ";
               break;
          }
          case 3: {
               text = "ba tram ";
               break;
          }
          case 4: {
               text = "bon tram ";
               break;
          }
          case 5: {
               text = "nam tram ";
               break;
          }
          case 6: {
               text = "sau tram ";
               break;
          }
          case 7: {
               text = "bay tram ";
               break;
          }
          case 8: {
               text = "tam tram ";
               break;
          }
          case 9: {
               text = "chin tram ";
               break;
          }
     }

     switch (hang_chuc) {
          case 0: {
               text += "le ";
               break;
          }
          case 1: {
               text += "mot muoi ";
               break;
          }
          case 2: {
               text += "hai muoi ";
               break;
          }
          case 3: {
               text += "ba muoi ";
               break;
          }
          case 4: {
               text += "bon muoi ";
               break;
          }
          case 5: {
               text += "nam muoi ";
               break;
          }
          case 6: {
               text += "sau muoi ";
               break;
          }
          case 7: {
               text += "bay muoi ";
               break;
          }
          case 8: {
               text += "tam muoi ";
               break;
          }
          case 9: {
               text += "chin muoi ";
               break;
          }
     }

     switch (hang_don_vi) {
          case 1: {
               text += "mot";
               break;
          }
          case 2: {
               text += "hai";
               break;
          }
          case 3: {
               text += "ba";
               break;
          }
          case 4: {
               text += "bon";
               break;
          }
          case 5: {
               text += "lam";
               break;
          }
          case 6: {
               text += "sau";
               break;
          }
          case 7: {
               text += "bay";
               break;
          }
          case 8: {
               text += "tam";
               break;
          }
          case 9: {
               text += "chin";
               break;
          }
     }

     cout << text << endl;
     return;


}

int main() {

     getTextOfLessThan4DigitsNumber(137);
     return 0;
}
