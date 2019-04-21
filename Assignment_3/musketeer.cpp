/*
    * Ho Chi Minh City University of Technology
    * Faculty of Computer Science and Engineering
    * Initial code for Assignment 2b
    * Programming Fundamentals CO1011 - Spring 2019
    * Author: Tran Ngoc Bao Duy
    * Date: 16.4.2019
    * Implementation of the header musketeer.h. You will write/edit this file to complete this assignment.
*/
#include "musketeer.h"
bool isPrimeNumber(int);



void advanture(int R, int N, int ID, int M, int* E, int nEvents) {
    // TODO: Simulate the advanture of musketeer
    int hp;
    switch (ID) {
        case 1: {
            hp = 999;
            break;
        }
        case 2: {
            hp = 900;
            break;
        }
        case 3: {
            hp = 888;
            break;
        }
        case 4: {
            hp = 777;
            break;
        }
    }

    int kim_cuong = 0;
    /*  1 -> d’Artagnan
        2 -> Athos
        3 -> Porthos
        4 -> Aramis */


    for (int i = 1; i <= nEvents; ++i) {
        // stop condition
        if (kim_cuong == N) {
            R = hp + M;
            cout << R;
            return;
        }
        if (hp <= 0) {
            cout << -1;
            return;
        }

        // events processing

        if (E[i-1] == 0) ++kim_cuong;

        else if (E[i-1] > 99 and E[i-1] < 200) {
            switch(ID) {
                case 2: {
                    int h1 = i % (100 + R);
                    int h2 = E[i-1] % (100 + R);
                    if (h1 < h2) {
                        if (isPrimeNumber(h2)) hp -= E[i-1];
                    }
                    break;
                }

                default: {
                    int h1 = i % (100 + R);
                    int h2 = E[i-1] % (100 + R);
                    if (h1 >= h2) {
                    M += E[i-1];
                    M = 999 ? (M > 999) : M;
                    }
                    else {
                        hp -= E[i-1];
                    }
                    break;
                }
            }
            
        }

    }

    cout << 0;

}

bool isPrimeNumber(int num) {
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false;
    for (int i = 3; i < num/2; i+=2) {
        if (num % i == 0) return false;
    }
    return true;
}