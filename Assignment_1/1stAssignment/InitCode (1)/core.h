//
// Created by Nguyen Duc Dung on 2019-02-15.
//

#ifndef A01_CORE_H
#define A01_CORE_H

/*TODO: If you are using some global variables and you intent to let other
 * users access it, you better declare it here.
 * Hint: use extern as shown in the below
 */
extern bool __coreInitialized;
extern int  __userChoice;
extern bool __isExiting;

/**
 * Function: Initialization
 * Purpose:  Initialize anything necessary in your program before starting
 * Input:    None
 * Output:   None
 */
void Initialization();
/**
 * Function: Finalization
 * Purpose:  Clean up everything before the program exits
 * Input:    None
 * Output:   None
 */
void Finalization();
void LoadConfiguration();
void LoadMenu();
void DisplayMenu();
void ProcessUserChoice();
bool isNum(std::string s);



#endif //A01_CORE_H
