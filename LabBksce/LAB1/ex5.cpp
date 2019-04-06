#include <iostream>
#include <iomanip>
#include <cmath>
#define EPSILON 1e-6
using namespace std;

int checkTriangle (double a, double b, double c) {

     if (fabs(a - b) < EPSILON && fabs(b - c) < EPSILON )
          return 4;
     else if (fabs(a - b) < EPSILON || fabs(b - c) < EPSILON || fabs(a - c) < EPSILON) {
          if (fabs(a * a + b * b - c * c) < EPSILON || fabs(a * a + c * c - b * b) < EPSILON || fabs(b * b + c * c - a * a) < EPSILON) 
               return 3;
          else
               return 1;
     }
     else if (fabs(a * a + b * b - c * c) < EPSILON || fabs(a * a + c * c - b * b) < EPSILON || fabs(b * b + c * c - a * a) < EPSILON)
          return 2;
     else 
          return 0;

}
// Driver code.
// recheck all failed testcases
int main () {
     cout << checkTriangle(432.4, 432.401, 432.4) << endl; // can 1
     cout << checkTriangle(377.663, 377.663, 377.663) << endl; // deu 4
     cout << checkTriangle(651.3886487905359, 634.6, 146.9354) << endl; // vuong 2
     cout << checkTriangle(191.9969, 191.9969, 191.9969)<< endl; // deu 4
     cout << checkTriangle(763.05, 763.05, 763.05)<< endl; // deu 4 
     cout << checkTriangle(672.9, 672.9, 672.9)<< endl; // deu  4

     return 0;
}

// if (a == b && b == c) {
//           // tam giac deu
//           return 4;
//      }
//      if (a == b || b == c || b == c) {
//           if ((pow(a,2) + pow(b, 2).5) == pow(c * c).5 || (c * c + b * b) == (a * a) || (a * a + c * c) == (b * b))
//                return 3; // vuong can
//           else return 1; // can
//      }

//      if ((a * a + b * b) == (c * c) || (c * c + b * b) == (a * a) || (a * a + c * c) == (b * b))
//           // tam giac vuong
//           return 2;
//       return 0; 