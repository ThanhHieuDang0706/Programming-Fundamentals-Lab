/*
    * Ho Chi Minh City University of Technology
    * Faculty of Computer Science and Engineering
    * Initial code for Assignment 1b
    * Programming Fundamentals CO1011 - Spring 2019
    * Author: Tran Ngoc Bao Duy
    * Date: 05.4.2019
    * Only write/edit in the body of combat function to complete this assignment
*/

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
using namespace std;

void combat(int hp1, int hp2, int d) {
    // TODO: You have to complete this function followed by requirements
    


}

int readFile(string filename, int& hp1, int& hp2, int& d) {
    ifstream myfile(filename);
    if (myfile.is_open()) {
        myfile >> hp1 >> hp2 >> d;

        return 1;
    }
    else return 0;
}

int main(int argc, char** argv) {
    if (argc == 2) {
        int hp1 = 0;
        int hp2 = 0;
        int d = 0;

        int readInput = readFile(argv[1], hp1, hp2, d);
        
        if (readInput) combat(hp1, hp2, d);
        else cout << "Cannot read input file";
    }
    else cout << "Incorrect arguments format";
}