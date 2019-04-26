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
    continue;
    }
    case 2:{
    text = "hai mươi";
    continue;
    }
    case 3: {
    text = "ba mươi";
    continue;
    }
    case 4: {
    text = "bốn mươi";
    continue;
    }
    case 5: {
    text = "năm mươi";
    continue;
    }
    case 6: {
    text = "sáu mươi";
    continue;
    }
    case 7: {
    text = "bảy mươi";
    continue;
    }
    case 8: {
    text = "tám mươi";
    continue;
    }
    case 9: {
    text = "chín mươi";
    continue;
    }
    }


    if (hang_don_vi != 0 && hang_chuc != 0) {
        text += " ";
    }

    switch (hang_don_vi) {
    case 1:{
    text += "một";
    continue;
    }
    case 2:{
    text += "hai";
    continue;
    }
    case 3: {
   text += "ba";
    continue;
    }
    case 4: {
    text += "bốn";
    continue;
    }
    case 5: {
    if (hang_chuc == 0)
        text += "năm";
    else text += "lăm";
    continue;
    }
    case 6: {
    text += "sáu";
    continue;
    }
    case 7: {
    text += "bảy";
    continue;
    }
    case 8: {
    text += "tám";
    continue;
    }
    case 9: {
    text += "chín"; 
    continue;
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
