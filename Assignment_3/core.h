/*
    * Ho Chi Minh City University of Technology
    * Faculty of Computer Science and Engineering
    * Initial code for Assignment 2b
    * Programming Fundamentals CO1011 - Spring 2019
    * Author: Tran Ngoc Bao Duy
    * Date: 16.4.2019
    * Header file for system function
*/
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <math.h>
using namespace std;

/*
    Read data from input file and assign values to all parameters
    * Input: The name of input file
    * Output parameters: R, N, ID, M and E array in the description
    * Output functions: The number of events in advanture
*/
int readFile(string filename, int& R, int& N, int& ID, int& M, int*& E);