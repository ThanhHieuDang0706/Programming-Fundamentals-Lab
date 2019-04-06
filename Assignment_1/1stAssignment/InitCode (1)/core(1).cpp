//
// Created by Nguyen Duc Dung on 2019-02-15.
//
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
// #ifdef __linux__
// #include <unistd.h>
// #elif _WIN32
// #include <chrono>
// #include <thread>
// #endif
using namespace std;
/// Prototype declaration
void Initialization();
void Finalization();
void displayWelcome();
void LoadConfiguration();
void LoadMenu();
void DisplayMenu();
void ProcessUserChoice();
bool isNum(std::string s);
///--------------------------------------------------------------------
const int lines_from_welcome = 9;
bool __coreInitialized = false;  /// an example of global variable
int  __userChoice;               /// a global variable to store user choice
bool __isExiting = false;        /// this variable should be turn on when the program exits
// TODO: add more global variables to complete tasks
std::string userInput;
std::string lineFromFile;


///--------------------------------------------------------------------
/**
 * Function: Initialization
 * Purpose:  Initialize anything necessary in your program before starting
 * Input:    None
 * Output:   None
 */

void Initialization() {
    LoadConfiguration();
    LoadMenu();
	  displayWelcome();
    // TODO: write the code to initialize the program
    __coreInitialized = true;
	// I don't know if this font is okay.
}

/**
 * Function: Finalization
 * Purpose:  Clean up everything before the program exits
 * Input:    None
 * Output:   None
 */
void Finalization() {
    // TODO: write the code to clean up when the program exits
// #ifdef __linux__
// 	system("clear");
// #elif _WIN32
// 	system("cls");
// #endif
	cout << "Program exiting. Press Enter to exit.\n";
	getchar();
}

void LoadConfiguration() {
    // TODO: write code to load data from the configuration file

}

void LoadMenu() {
    // TODO: write code to load menu from the configuration file


}

void DisplayMenu() {
    // TODO: Display the menu loaded from configuration file
	ifstream myfile ("conf.json", ifstream::in);
	if (!myfile) {
		perror("Cannot open file.");
		exit(EXIT_FAILURE);
	}
	// Get to Menu
	cout << '\n';
	for (int i = 0; i < 18; ++i)
		getline(myfile, lineFromFile);

	for (int i = 0; i < 5; ++i){
		cout << i + 1 << ". ";
		getline(myfile, lineFromFile);
		// Calculate the distance between first " and last " after the :
		size_t dau_hai_cham = lineFromFile.find(":");
		size_t ngoac_kep_dau_tien = lineFromFile.find("\"", dau_hai_cham);
		size_t ngoac_kep_cuoi = lineFromFile.find("\"", ngoac_kep_dau_tien + 1);
		size_t RequestedSize = lineFromFile.length() - ngoac_kep_dau_tien - (lineFromFile.length() - ngoac_kep_cuoi);
		cout << lineFromFile.substr(ngoac_kep_dau_tien + 1, RequestedSize - 1) << '\n';
	}
	myfile.close();


}

void ProcessUserChoice() {
    // TODO: Read user input and process
	cout << "Please select : ";
	// Store input as a string

	getline(cin, userInput);
	// Process Invalid Choice
	if (!(isNum(userInput))) {
		cout << "Invalid input. Please input an integer number.\n\n";
		return;
	}
	//Turn input to an int if success
	stringstream(userInput) >> __userChoice;


	if (__userChoice > 5 or __userChoice <= 0){
		cout << "Please select a number from 1 to 5.\n\n";
		return;
	} else if (__userChoice == 5) {
		__isExiting = true;
	} else {
		cout << "You select menu item " << __userChoice <<". Processing... Done\n";
		return;
	}


}

bool isNum(std::string s)
{
	int i = 0;
	// skip it some very first inputs are spaces and last of strings

	if (s.length() > 0) {
		// Trim left
		while (s[0] == ' ')
			s = s.substr(1);
		// Trim right
		while (s[s.length() - 1] == ' ')
			s = s.substr(0, s.length() - 1);
	}
	else {
		return false;
	}
     // ìf the first character is + or - we will accept it as valid input
	if (s[i] == '+' || s[i] == '-')
		++i;
     // Check if every character is a number since we need integer only
	for (; i < (int)s.length(); ++i) {
		if (isdigit(s[i]) == false)
			return false;
	}
    return true;
}

void displayWelcome(){
	ifstream myfile ("conf.json", ifstream::in);
	if (!myfile) {
		perror("Cannot open file.");
		exit(EXIT_FAILURE);
	}

	// get to welcome
	for (int i = 0; i < 7; ++i)
		getline(myfile, lineFromFile);
	//get every line from that
	for (int i = 0; i < 9; ++i){
		getline(myfile, lineFromFile);
		// Calculate the position of the first "" and print the substring of it (only ones in "" are printed out).
		size_t dau_hai_cham = lineFromFile.find(":");
		size_t ngoac_kep_dau_tien = lineFromFile.find("\"", dau_hai_cham);
		size_t ngoac_kep_cuoi = lineFromFile.find("\"", ngoac_kep_dau_tien + 1);
		// The distance between the first colon and the last colon after the "linex"
		size_t RequestedSize = lineFromFile.length() - ngoac_kep_dau_tien - (lineFromFile.length() - ngoac_kep_cuoi);
		cout << lineFromFile.substr(ngoac_kep_dau_tien + 1, RequestedSize - 1) << '\n';
	}
	myfile.close();

}
