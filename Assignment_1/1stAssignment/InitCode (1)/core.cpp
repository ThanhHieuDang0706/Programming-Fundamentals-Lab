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

bool __coreInitialized = false;  /// an example of global variable
int  __userChoice;               /// a global variable to store user choice
bool __isExiting = false;        /// this variable should be turn on when the program exits
// TODO: add more global variables to complete tasks
std::string userInput;
const int line_in_welcome = 9;
const int line_in_menu = 5;


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

}

/**
 * Function: Finalization
 * Purpose:  Clean up everything before the program exits
 * Input:    None
 * Output:   None
 */
void Finalization() {
    // TODO: write the code to clean up when the program exits

	cout << "Exiting...\n";
}

void LoadConfiguration() {
    // TODO: write code to load data from the configuration file

}

void LoadMenu() {
    // TODO: write code to load menu from the configuration file


}

void DisplayMenu() {
    // TODO: Display the menu loaded from configuration file
	// open file
	ifstream myfile ("conf.json", ifstream::in);
	if (!myfile) {
		perror("Cannot open file.");
		exit(EXIT_FAILURE);
	}
	// Get to Menu
	string temp;
	for (int i = 0; i < 18; ++i)
		getline(myfile, temp);
		
	vector <string> line;
	
	// put lines in a vector
	for (int i = 0; i < line_in_menu; ++i) {
		getline(myfile, temp);
		line.push_back(temp);
	}
	// Get order in the file
	vector <string> order;
	for (int i = 0 ; i < line_in_menu; ++i) {
		size_t dau_ngoac_kep_dau_tien = line.at(i).find("\"");
		size_t dau_ngoac_kep_thu_hai_tu_cai_thu_nhat = line.at(i).find("\"", dau_ngoac_kep_dau_tien);
		size_t dau_ngoac_kep_thu_hai = dau_ngoac_kep_dau_tien + dau_ngoac_kep_thu_hai_tu_cai_thu_nhat;
		size_t chu_cai_ngay_truoc_so_thu_tu = line.at(i).find("t");
		size_t do_dai_de_lay_ky_tu_so_start = dau_ngoac_kep_thu_hai - chu_cai_ngay_truoc_so_thu_tu; 
//		cout << line.at(i).substr(chu_cai_ngay_truoc_so_thu_tu + 1, do_dai_de_lay_ky_tu_so_start) << endl;
		order.push_back(line.at(i).substr(chu_cai_ngay_truoc_so_thu_tu + 1, do_dai_de_lay_ky_tu_so_start));
	}
	// cast the order to integer for swapping and comparing
	vector <int> order_in_number;
	for (int i = 0; i <	(int)	 order.size() ; ++i){
		order_in_number.push_back(stoi(order.at(i)));
	}
	// Code for swapping to be in order
	for (int i = 0; i < line_in_menu; ++i) {
		for (int j = i + 1; j < line_in_menu; ++j) {
			if (order_in_number.at(j) < order_in_number.at(i)){
				int num = order_in_number.at(i);
				order_in_number.at(i) = order_in_number.at(j);
				order_in_number.at(j) = num;
				temp = line.at(i);
				line.at(i) = line.at(j);
				line.at(j) = temp;
			}
		}
	}
	
	for (int i = 0; i < line_in_menu; ++i) {
		// Calculate the position of the first "" and print the substring of it (only ones in "" are printed out).
		cout << order_in_number.at(i) << ". ";
		size_t dau_hai_cham =line.at(i).find(":");
		size_t ngoac_kep_dau_tien = line.at(i).find("\"", dau_hai_cham);
		size_t ngoac_kep_cuoi = line.at(i).find("\"", ngoac_kep_dau_tien + 1);
		// The distance between the first colon and the last colon after the "linex"
		size_t RequestedSize = line.at(i).length() - ngoac_kep_dau_tien - (line.at(i).length() - ngoac_kep_cuoi);
		cout << line.at(i).substr(ngoac_kep_dau_tien + 1, RequestedSize - 1) << '\n';
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
	//Turn input to an int if input is valid
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
	string temp;
	for (int i = 0; i < 7; ++i)
		getline(myfile, temp);
	
	vector <string> line;
	// put lines in vector
	for (int i = 0; i < line_in_welcome; ++i) {
		getline(myfile, temp);
		line.push_back(temp);
//		cout << line.at(i);
	}
	
	// get the number type strings

	vector <string> order;
	for (int i = 0 ; i < line_in_welcome; ++i) {
		size_t dau_ngoac_kep_dau_tien = line.at(i).find("\"");
		size_t dau_ngoac_kep_thu_hai_tu_cai_thu_nhat = line.at(i).find("\"", dau_ngoac_kep_dau_tien);
		size_t dau_ngoac_kep_thu_hai = dau_ngoac_kep_dau_tien + dau_ngoac_kep_thu_hai_tu_cai_thu_nhat;
		size_t chu_cai_ngay_truoc_so_thu_tu = line.at(i).find("e");
		size_t do_dai_de_lay_ky_tu_so_start = dau_ngoac_kep_thu_hai - chu_cai_ngay_truoc_so_thu_tu; 
//		cout << line.at(i).substr(chu_cai_ngay_truoc_so_thu_tu + 1, do_dai_de_lay_ky_tu_so_start + 1) << endl;
		order.push_back(line.at(i).substr(chu_cai_ngay_truoc_so_thu_tu + 1, do_dai_de_lay_ky_tu_so_start + 1));	// THE DIFFERENCE from DisplayMenu. Don't know why.?
	}
	// convert the order to integer for swapping and comparing
	vector <int> order_in_number;
	for (int i = 0; i <	(int) order.size() ; ++i){
		order_in_number.push_back(stoi(order.at(i)));

	}
	
	for (int i = 0; i < line_in_welcome; ++i) {
		for (int j = i + 1; j < line_in_welcome; ++j) {
			if (order_in_number.at(j) < order_in_number.at(i)){
				int num = order_in_number.at(i);
				order_in_number.at(i) = order_in_number.at(j);
				order_in_number.at(j) = num;
				temp = line.at(i);
				line.at(i) = line.at(j);
				line.at(j) = temp;
			}
		}
	}
	
	for (int i = 0; i < line_in_welcome; ++i) {
		// Calculate the position of the first "" and print the substring of it (only ones in "" are printed out).
		size_t dau_hai_cham =line.at(i).find(":");
		size_t ngoac_kep_dau_tien = line.at(i).find("\"", dau_hai_cham);
		size_t ngoac_kep_cuoi = line.at(i).find("\"", ngoac_kep_dau_tien + 1);
		// The distance between the first colon and the last colon after the "linex"
		size_t RequestedSize = line.at(i).length() - ngoac_kep_dau_tien - (line.at(i).length() - ngoac_kep_cuoi);
		cout << line.at(i).substr(ngoac_kep_dau_tien + 1, RequestedSize - 1) << '\n';
	}
	myfile.close();
	return;
}
