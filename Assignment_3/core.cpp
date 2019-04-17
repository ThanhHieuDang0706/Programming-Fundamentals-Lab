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

        E = new int[numOfSpaces + 1];

        int index = 0;
        int spacePosition = 0;
        
        while (events.length() > 0) {
            spacePosition = events.find(' ', 0);
            if (spacePosition == -1) break;
            E[index++] = stoi(events.substr(0, spacePosition));
            events = events.substr(spacePosition + 1);
        }
        
        result = numOfSpaces + 1;
    }
    else result = 0;

    fs.close();
    return result;
}