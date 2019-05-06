#include <iostream>

using namespace std;

int main(){
    int n;
    cout << "Nhap so nguyen n: ";
    cin >> n;
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= 2n -1 ; ++j) {
            cout << ' ';
        }
        for (int j = 1; j <= i; j++) {
            cout <<"* ";
        }
    }
    return 0;
}