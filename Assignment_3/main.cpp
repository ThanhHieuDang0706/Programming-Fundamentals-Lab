#include "musketeer.h"

int main(int argc, char** argv) {
    if (argc == 2) {
        string filename = argv[1];

        int R, N, ID, M;
        int* E;

        int nEvents = readFile(filename, R, N, ID, M, E);

        if (nEvents >= 0)
            advanture(R, N, ID, M, E, nEvents);
        else cout << "Cannot read input file or no events in advanture";
    }
    else cout << "Invalid argument list. Please try again";
    
    return 0;
}