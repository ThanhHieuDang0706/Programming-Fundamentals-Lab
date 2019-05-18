#include "musketeer.h"

// Global Constant
#define NUM_OF_MUSKETEERS   4
#define NUM_OF_CYSTAL       3

class Battle {
    private:
        Musketeer* musketeers;
        int* events;
        int firstMusketeer;
        int numOfEvents;

        MemoryManager* manager;

    public:
        Battle(MemoryManager* manager);
        ~Battle();
        bool readDataFromFile(string);
        void display();
        void struggle();
        void finalize();
};