#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>
#include <cassert>

#include "core.h"

using namespace std;

int main() {
    Initialization();

    void*   pData;
    void*   pOutput;
    int     N;

    LoadData("diabetes.csv", pData);

    string req;
    while (true) {
        req = "";
        getline(cin, req);
        if (cin.bad()) {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        if (req == "Exit") break;
        ProcessRequest(req.data(), pData, pOutput, N);
        PrintOutput(req.data(), pData, pOutput, N);
    }

    ReleaseData(pData);

    Finalization();
    return 0;
}