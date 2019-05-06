/*
    * Ho Chi Minh City University of Technology
    * Faculty of Computer Science and Engineering
    * Initial code for Assignment 2b
    * Programming Fundamentals CO1011 - Spring 2019
    * Author: Tran Ngoc Bao Duy
    * Date: 16.4.2019
    * Implementation of the header core.h
*/
#include "core.h"

int readFile(string filename, int& R, int& N, int& ID, int& M, int*& E) {
    fstream fs(filename);
    
    int result = -1;
    if (fs.is_open()) {
        fs >> R;
        fs >> N;
        fs >> ID;
        fs >> M;

        string events; fs.ignore();
        getline(fs, events);

        int numOfSpaces = 0;
        for (int i = 0; i < events.length(); i++) {
            if (events.at(i) == ' ') numOfSpaces++;
        }

        int numOfEvents = numOfSpaces + 1;

        E = new int[numOfEvents];

        stringstream ss(events);

        for (int i = 0; i < numOfEvents; i++)
            ss >> E[i];
        
        result = numOfEvents;
    }
    else result = 0;

    fs.close();
    return result;
}