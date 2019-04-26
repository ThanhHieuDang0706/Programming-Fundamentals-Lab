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
#include <iomanip>
using namespace std;

void combat(int hp1, int hp2, int d) {
    // TODO: You have to complete this function followed by requirements
    double p;
    double p1 = (double)hp1 * (double)(1000.00l - d) / (double)1000.00;
    double p2 = (double)hp2 * (double)d / (double)1000.00;
    int h1 = (hp1 + hp2) % 100;
    int h2 = (h1 * hp2) % 100;

    p = ((double)h1 * p1 - (double)h2 * p2) / ((double)h1 * p1 + (double)h2 * p2);

    //process p as described if p is negative or greater than 1
    if (p <= 0.00l) p = 0.00l;
    else if (p >= 1.00l) p = 1.00l;

    // Mau = 0
    if (((double)h1 * p1 + (double)h2 * p2) == 0.00l) {
        if (h1 == 0 && h2 ==0) p = 0.00l;
        else if (p1 < p2) p = 0.00l;
        else p = 1.00l;
    }   

    switch (d) {
        case 987: {
            if (h1 + h2 != 99) {
                if (hp1 != 999) p = 0.00l;
            }
            continue;
        }
        default: {
            switch (hp2) {
                case 888: {
                    switch(hp1) {
                        case 777 : continue;
                        case 888 : continue;
                        case 900 : continue;
                        case 999 : {
                        //     if (d == 987) {
                        //     continue;
                        // }
                            p = 1.00l;
                            continue;
                        }
                        default : {
                            p = 0.01l;
                            continue;
                        }
                    }
                    continue;                  
                }
                default : {
                    switch (hp1) {
                        case 777: {
                                if (p1 < p2 || h1 < h2) {
                                    d = 1;
                                    p1 = (double)hp1 * (double)(1000.00l - d) / (double)1000.00;
                                    p2 = (double)hp2 * (double)d / (double)1000.00;
                                    p = ((double)h1 * p1 - (double)h2 * p2) / ((double)h1 * p1 + (double)h2 * p2);
                            }
                            continue;
                        }

                        case 888 : { 
                            h1 *= 10; // Don't change h2 accordingly
                            p = ((double)h1 * p1 - (double)h2 * p2) / ((double)h1 * p1 + (double)h2 * p2);
                            continue;
                        }

                        case 900 : {
                            if  (p < 0.50l) p = 0.50l;
                            continue;    
                        }   
                    }

                    if (d != 987) { // Since with d = 987 and with special pairs of hp1 and hp2 below, it will end up a different result
                        if ((hp1 == 220 && hp2 == 284) || (hp1 == 284 && hp2 == 220)) p = 0.50l; 
                    }
                    else { // in the case of d = 987 we have 2 situations as below
                        if ((h1 + h2) != 99) { 
                            if (hp1 != 999) p = 0.00l;
                        }
                    }
                    continue;   
                } 
            }
        }
    }


    /* process the output */
    cout << fixed << setprecision(2) << p;


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