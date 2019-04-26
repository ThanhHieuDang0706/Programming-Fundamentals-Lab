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
int Fibonacci(int num);


void advanture(int R, int N, int ID, int M, int* E, int nEvents) {
    // TODO: Simulate the advanture of musketeer
    const int original_hp[5] = {0, 999, 900, 888, 777};

    int hp;
    

    switch (ID) {
        case 1: {
            hp = original_hp[ID];
            continue;
        }
        case 2: {
            hp = original_hp[ID];
            continue;
        }
        case 3: {
            hp = original_hp[ID];
            continue;
        }
        case 4: {
            hp = original_hp[ID];
            continue;
        }
    }

    int kim_cuong = 0;
    bool win_gws = false;
    bool gap_gai = false;
    const double alpha = ((double)R + 10.) / (pow(2,R+5));
    bool pothos_with_titan = false;


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

        if (E[i-1] > 99 and E[i-1] < 200) {
            int h1 = i % (100 + R);
            int h2 = E[i-1] % (100 + R);
            switch(ID) { // gap ve binh
                case 2: {
                    
                    if (h1 < h2) {
                        if (isPrimeNumber(h2)) hp = (win_gws) ? (hp - round(alpha*double(E[i-1]))) : (hp - E[i-1]);
                    }
                    continue;
                }

                case 4: {
                    if (h1 < h2) {
                        tmp_hp = hp;
                        tmp_hp = (win_gws) ? (tmp_hp - round(alpha*double(E[i-1]))) : (tmp_hp - E[i-1]);
                        if (tmp_hp >= 1) hp = tmp_hp;
                    } else {
                        M += E[i-1];
                        M = (M > 999) ? 999 : M;
                    }
                }
                
                case 3: {
                    if (pothos_with_titan) continue;
                }
                
                default: {
                    if (h1 >= h2) {
                        M += E[i-1];
                        M = (M > 999) ? 999 : M;
                    }
                    else {
                        hp = (win_gws) ? (hp - round(alpha*double(E[i-1]))) : (hp - E[i-1]);
                    }
                    continue;
                }
            }
        }

        if (E[i-1] == 1) { // nha tro
            switch (ID) {
                case 2: {
                    int P = R;
                    do {
                        --P;
                    } while (!isPrimeNumber(P));

                    while (hp < original_hp[ID] && M-P >= 0 && M>2) {
                        ++hp;
                        M -= P;
                    }
                    continue;
                }
                default: {
                    while (hp < original_hp[ID] & M > 0) {
                        ++hp;
                        --M;
                    }
                    continue;
                }
            }
        }

        if (E[i-1] > 199 && E[i-1] < 300) { // gap lai buon
            int h1 = i % (100 + R);
            int h2 = E[i-1] % (100 + R);
            if (h1 < h2) M /= 2;
            else {
                M *= 2;
                M = (M > 999) ? 999 : M;
            }
        }

        if (E[i-1] > 299 && E[i-1] < 400) { // gap chien binh gws
            if (!win_gws) {
                int h1 = i % (100 + R);
                int h2 = E[i-1] % (100 + R);
                if (h1 < h2) kim_cuong = 0;
                else {
                    win_gws = true;
                }
            }
        }

        if (E[i-1] > 499 && E[i-1] < 600) { // titan
            int h1 = i % (100 + R);
            int h2 = E[i-1] % (100 + R);
            switch(ID) {
                case 3: {
                    pothos_with_titan = true;
                    continue;
                }
                case 4: {
                    if (h1 < h2) {
                        tmp_hp = hp;
                        tmp_hp = (win_gws) ? (tmp_hp - round(alpha*double(E[i-1]))) : (tmp_hp - E[i-1]);
                        if (tmp_hp >= 1) hp = tmp_hp;
                    } 
                    continue; //skip if win anyway cause' fighting agains titan earns nothing
                }
                default: { 
                    if (h1 < h2) {
                        hp = (win_gws) ? (hp - round(alpha*double(E[i-1]))) : (hp - E[i-1]);
                    }
                    continue;
                }
            }
        }

        if (E[i-1] == 666) { // milady
            switch (ID) {
                case 1: {
                    cout << -1;
                    return;
                    continue;
                }
                case 2: {
                    M = 999;
                    continue;
                }
                default: {
                    int i = 1;
                    if (hp >= 2) {
                        while (Fibonacci(i++) < hp);
                        hp = Fibonacci(i-1);
                    }
                    continue;
                }
            }
            
        }

        if (E[i-1] == 777) { // gap gai
            if (!gap_gai) {
                if (kim_cuong){ 
                    --kim_cuong;

                    int Q = R;

                    if (isPrimeNumber(R)) {

                    }
                    

                    if (ID == 4) {

                    }

                }
            }

            gap_gai = true;
        }


            
            
    }
    cout << 0;
}

    



    /*  1 -> d’Artagnan
        2 -> Athos
        3 -> Porthos
        4 -> Aramis */

bool isPrimeNumber(int num) {
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false;
    for (int i = 3; i < num/2; i+=2) {
        if (num % i == 0) return false;
    }
    return true;
}

int Fibonacci(int num) {
    if (num == 0) return 0;
    else if (num == 1 || num == 2) return 1;
    else {
        return Fibonacci(num-1) + Fibonacci(num-2);
    }
}

// int main () {
//     return 0;
// }