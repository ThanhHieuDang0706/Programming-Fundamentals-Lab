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
    float p;
    float p1 = (float)hp1 * (float)(1000.00l - d) / (float)1000.00;
    float p2 = (float)hp2 * (float)d / (float)1000.00;
    int h1 = (hp1 + hp2) % 100;
    int h2 = (h1 * hp2) % 100;

    p = ((float)h1 * p1 - (float)h2 * p2) / ((float)h1 * p1 + (float)h2 * p2);

    if (p < 0.00l) p = 0.00f;
    if (p > 1.00l) p = 1.00f;
    //FAILED TESTCASE 38 ONLY
    // Mau = 0
    if (((float)h1 * p1 + (float)h2 * p2) == 0.) {
        if (h1 == 0 && h2 ==0) p = 0.00f;
        else if (p1 < p2) p = 0.00f;
        else p = 1.00f;
    }   

        /* Since if hp2 = 888 and hp1 = special numbers
        all of the ablilities of hp1 will be useless 
        so we will consider 2 conditions of hp2 here
        Attention that in each condition of hp2 I use switch case statements
        because writing with if else statement is super complicated
        especially with the case of hp == 882 */
    if (hp2 != 888) {
        switch (hp1) {
            case 777: {
                    if (p1 < p2 || h1 < h2) {
                    d = 1;
                    p1 = (float)hp1 * (float)(1000.00f - d) / (float)1000.00;
                    p2 = (float)hp2 * (float)d / (float)1000.00;
                    p = ((float)h1 * p1 - (float)h2 * p2) / ((float)h1 * p1 + (float)h2 * p2);
                }
                    break;
            }
        
            case 888 : { 
                h1 *= 10; // Don't change h2 accordingly
                p = ((float)h1 * p1 - (float)h2 * p2) / ((float)h1 * p1 + (float)h2 * p2);
                break;
            }
    
            case 900 : {
                if  (p < 0.50f) p = 0.50f;
                break;    
            }   
        }

        if (d != 987) { // Since with d = 987 and with special pairs of hp1 and hp2 below, it will end up a different result
            if ((hp1 == 220 && hp2 == 284) || (hp1 == 284 && hp2 == 220)) p = 0.50f; 
        }
        else { // in the case of d = 987 we have 2 situations as below
            if ((h1 + h2) != 99) { 
                if (hp1 != 999) p = 0.00f;
            }
        }
    } 
    else { // hp2 = 888 
        switch (hp1) { // At this point writing if statement here would be the pain in the ass
            case 777 : break;
            case 888 : break;
            case 900 : break;
            case 999 : {
                p = 1.00f;
                break;
            }
            default : {
                p = 0.01f;
                break;
            }
        }      
    }

    /* process the output */

    
    cout << fixed << setprecision(2) << p;


}

// int readFile(string filename, int& hp1, int& hp2, int& d) {
//     ifstream myfile(filename);
//     if (myfile.is_open()) {
//         myfile >> hp1 >> hp2 >> d;

//         return 1;
//     }
//     else return 0;
// }

int main(int argc, char** argv) {
    // if (argc == 2) {
    //     int hp1 = 0;
    //     int hp2 = 0;
    //     int d = 0;

    //     int readInput = readFile(argv[1], hp1, hp2, d);
        
    //     if (readInput) combat(hp1, hp2, d);
    //     else cout << "Cannot read input file";
    // }
    // else cout << "Incorrect arguments format";
    combat(900, 888, 700);
    return 0;
}