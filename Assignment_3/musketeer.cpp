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
bool isFibo(int n);


void advanture(int R, int N, int ID, int M, int* E, int nEvents) {
    // TODO: Simulate the advanture of musketeer
    const int original_hp[5] = {0, 999, 900, 888, 777};

    int hp;
    

    switch (ID) {
        case 1: {
            hp = original_hp[ID];
            break;
        }
        case 2: {
            hp = original_hp[ID];
            break;
        }
        case 3: {
            hp = original_hp[ID];
            break;
        }
        case 4: {
            hp = original_hp[ID];
            break;
        }
    }

    int kim_cuong = 0;
    bool win_gws = false;
    bool gap_gai = false;
    const double alpha = ((double)R + 10.) / (pow(2,R+5));
    bool pothos_with_titan = false;


    for (int i = 1; i <= nEvents; ++i) {
        const int h1 = i % (100 + R);
        const int h2 = E[i-1] % (100 + R);
        

        // events processing

        if (E[i-1] == 0) ++kim_cuong;

        else if (E[i-1] > 99 and E[i-1] < 200) {
            switch(ID) { // gap ve binh
                case 2: {
                    if (h1 < h2) {
                        if (isPrimeNumber(h2) && h2 > M) hp = (win_gws) ? (hp - round(alpha*double(E[i-1]))) : (hp - E[i-1]);
                    }
                    break;
                }

                case 4: {
                    if (h1 < h2) {
                        int tmp_hp = hp;
                        tmp_hp = (win_gws) ? (tmp_hp - round(alpha*double(E[i-1]))) : (tmp_hp - E[i-1]);
                        if (tmp_hp >= 1) hp = tmp_hp;
                    } else {
                        M += E[i-1];
                        M = (M > 999) ? 999 : M;
                    }
                    break;
                }
                
                case 3: {
                    if (pothos_with_titan) break;
                }
                
                default: {
                    if (h1 >= h2) {
                        M += E[i-1];
                        M = (M > 999) ? 999 : M;
                    }
                    else {
                        hp = (win_gws) ? (hp - round(alpha*double(E[i-1]))) : (hp - E[i-1]);
                    }
                    break;
                }
            }
        }

        else if (E[i-1] == 1) { // nha tro
            switch (ID) {
                case 3: {
                    bool giao_dich;

                    if (R < 3) giao_dich = false;
                    else if (M <= 2) giao_dich = false;
                    else giao_dich = true;

                    if (giao_dich) {
                        int P = R;

                        do {
                            --P;
                        } while (!isPrimeNumber(P));

                        while (hp < original_hp[ID] && M-P >= 0) {
                            ++hp;
                            M -= P;
                        }
                    }
                    break;
                }

                default: {
                    while (hp < original_hp[ID] && M > 0) {
                        ++hp;
                        --M;
                    }
                    break;
                }
            }
        }

        else if (E[i-1] > 199 && E[i-1] < 300) { // gap lai buon
            if (h1 < h2) M /= 2;
            else {
                M *= 2;
                M = (M > 999) ? 999 : M;
            }
        }

        else if (E[i-1] > 299 && E[i-1] < 400) { // gap chien binh gws
            if (!win_gws) {
                if (h1 < h2) kim_cuong = 0;
                else {
                    win_gws = true;
                }
            }
        }

        else if (E[i-1] > 499 && E[i-1] < 600) { // titan
            switch(ID) {
                case 3: {
                    pothos_with_titan = true;
                    break;
                }
                case 4: {
                    if (h1 < h2) {
                        int tmp_hp = hp;
                        tmp_hp = (win_gws) ? (tmp_hp - round(alpha*double(E[i-1]))) : (tmp_hp - E[i-1]);
                        if (tmp_hp >= 1) hp = tmp_hp;
                    } 
                    break; //skip if win anyway cause' fighting agains titan earns nothing
                }
                default: { 
                    if (h1 < h2) {
                        hp = (win_gws) ? (hp - round(alpha*double(E[i-1]))) : (hp - E[i-1]);
                    }
                    break;
                }
            }
        }

        else if (E[i-1] == 666) { // milady
            switch (ID) {
                case 1: {
                    cout << -1;
                    return;
                    break;
                }
                case 2: {
                    M = 999;
                    break;
                }
                case 3:
                case 4: {
                    if (hp <= 2) break;
                }
                default: {
                    int tmp = 1;
                    while (Fibonacci(tmp) < hp) ++tmp;
                    hp = Fibonacci(tmp-1);
                    break;
                }
            }
            
        }

        else if (E[i-1] == 777) { // gap gai, unclear explaination
            if (!gap_gai) {
                gap_gai = true; 
                if (kim_cuong > 0){ 
                    --kim_cuong;
                    if (ID == 4) {
                        int Q;
                        bool foundQ = false;
                        if (isPrimeNumber(R)) {
                            Q = R;
                            foundQ = true;
                        } else {
                            for (int j = 2; j < R/2; ++j) {
                                if (R % j == 0 && isPrimeNumber(j)) {
                                    Q = j;
                                    foundQ = true;
                                }
                            }
                        }
                        if (!foundQ) Q = 1;
                        if (M >= Q) {
                            if (h1 >= h2) ++kim_cuong;
                            else M -= Q;
                        }
                    }
                }
            }
        }

        else if (E[i-1] == 999) {
            if (isFibo(i)) {
                if (h1 >= h2) {
                    hp = original_hp[ID];
                    M = 999;
                } else {
                    cout << "-1";
                    return;
                }
            } else {
                cout << "-1";
                return;
            }

        }
        
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
            
    }
    cout << 0;
}

    /*  1 -> d’Artagnan
        2 -> Athos
        3 -> Porthos
        4 -> Aramis */

bool isPrimeNumber(int n) {
    if (n <= 1) 
        return false; 
    if (n <= 3) 
        return true; 
  
    if (n % 2 == 0 || n % 3 == 0) 
        return false; 
  
    for (int i = 5; i * i <= n; i += 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
            return false; 
  
    return true; 
}

int Fibonacci(int n) {
    int n1 = 1;
    int n2 = 1;
    int result = 0;
    if (n == 2 || n == 1) return 1;
    if (n == 0) return 0;
    for (int i = 3; i <= n; ++i) {
        result = n1 + n2;
        n1 = n2;
        n2 = result;
    }
    return result;
}

bool isFibo(int n) {
    int tmp = 2;
    while (Fibonacci(tmp) < n) ++tmp;
    return (Fibonacci(tmp) == n);
}

int main () {
    int R = 0;
    int N = 12;
    int ID = 1;
    int M = 300;
    int e[] = {0, 101,999};
    int ne = sizeof(e)/sizeof(int);
    advanture(R,N,ID,M,e,ne);
    return 0;
}