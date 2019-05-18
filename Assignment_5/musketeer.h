#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
using namespace std;

/* Start block: DO NOT CHANGE
    * Please do not change anything in this code block (including whitespace, empty lines)
    * If changes, your submission is marked as zero.
*/

// Class declaration: Memory manager
class MemoryManager {
    private:
        int numOfAllocation;
    
    public:
        MemoryManager();
        int getNumOfAllocation();
        void allocate(int* &pointer);
        void deallocate(int* pointer);
};

// Class declaration: Musketeer
class Musketeer {
    private:
        int HP;
        int* pC1;
        int* pC2;
        int* pC3;

        MemoryManager* manager;
        Musketeer* team;

    public:
        Musketeer();
        ~Musketeer();
        void setMemoryManger(MemoryManager* manager);
        void setTeam (Musketeer* team);
        int* getCystalPointer(int index);
        void setCystalPointer(int index, int* pointer);
        int getHP();
        void setHP(int HP);
        void finalize();
/* End block: DO NOT CHANGE */

/* Start block: TO DO
    * You can declare additional methods to complete this assignment
*/

/* End block: TODO */
};