#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <math.h>
#include <cctype>
#define FILENAME "07001b_sol.cpp"
using namespace std;


class Integer {
	int value;
public:
    Integer(int i);
    void toString(char*& ch);
    int getVal();
};



void Integer::toString(char* &ch) {
    ch = new char[16];
    sprintf(ch, "%d", this->value);
}

void process(double d) {
	Integer i = d;
    cout << i.getVal() << endl;
	char* c = NULL;
	i.toString(c);
	printf("%s", c);
	delete[] c;
}

int Integer::getVal() {
    return this->value;
}

int main () {
    process(1);
    return 0;
}