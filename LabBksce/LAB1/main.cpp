#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>


using namespace std;

void getText (int number) {
    if (number >= 100)
        cout << "-1" ;
    else if (number < 100 && number > 0) {
    string text;

    int hang_don_vi = number % 10;
    int hang_chuc = number / 10;

    switch (hang_chuc) {
    case 1:{
    text = "mười";
    break;
    }
    case 2:{
    text = "hai mươi";
    break;
    }
    case 3: {
    text = "ba mươi";
    break;
    }
    case 4: {
    text = "bốn mươi";
    break;
    }
    case 5: {
    text = "năm mươi";
    break;
    }
    case 6: {
    text = "sáu mươi";
    break;
    }
    case 7: {
    text = "bảy mươi";
    break;
    }
    case 8: {
    text = "tám mươi";
    break;
    }
    case 9: {
    text = "chín mươi";
    break;
    }
    }


    if (hang_don_vi != 0 && hang_chuc != 0) {
        text += " ";
    }

    switch (hang_don_vi) {
    case 1:{
    text += "một";
    break;
    }
    case 2:{
    text += "hai";
    break;
    }
    case 3: {
   text += "ba";
    break;
    }
    case 4: {
    text += "bốn";
    break;
    }
    case 5: {
    if (hang_chuc == 0)
        text += "năm";
    else text += "lăm";
    break;
    }
    case 6: {
    text += "sáu";
    break;
    }
    case 7: {
    text += "bảy";
    break;
    }
    case 8: {
    text += "tám";
    break;
    }
    case 9: {
    text += "chín"; 
    break;
    }
    }
    cout << text;
    }
}

int main()
{   getText(85);
    cout << endl;
    getText(82);
    cout << endl;
    getText(43);
    cout << endl;
    getText(65);
    cout << endl;
    getText(4);
    cout << endl;
    getText(10);
    cout << endl;
    getText(68);
    cout << endl;
    getText(54);
    cout << endl;
    getText(112);
    cout << endl;
    getText(79);
    cout << endl;
    getText(104);
    cout << endl;
    getText(60);
    cout << endl;
    getText(56);
    cout << endl;
    getText(30);
    cout << endl;
    getText(37);
    cout << endl;
    cout << endl;
    system("pause");
    return 0;
}
