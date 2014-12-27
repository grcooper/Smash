#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <math.h>
#include "player.h"
#include "controller.h"

using namespace std;

//In order in .h file

//Private Methods:
//These will all be called in the constructor

//Sets the number of players field with user input
void Controller::SetNumPlayers(){
	cout << "How many players would you like to test for?" << endl;
	//TODO: ERROR CHECKING
	cin >> numPlayers;
	cout << "Set Number of Players to: " << numPlayers << endl; // Testing
}

//Sets the type of elo with user input
void Controller::SetTypeELO(){
	cout << "Should the ELO be random or standard(1200)?" << endl;
	cout << "Type [r]andom or [s]tandard." << endl;
	//TODO: ERROR CHECKING
	char choice;
	cin >> choice;
	if(choice == 'r'){
		randELO = true;
		cout << "Random ELO is set to true." << endl; //Testing
	}
	else {
		randELO = false;
		cout << "Random ELO is set to false." << endl; //Testing
	}
}

//Sets the high and low ELO for the random ELO distribution
//Uses user input
void Controller::SetHighLowELO(){
	cout << "Choose the highest ELO that you want to see: " << endl;
	cin >> highELO;
	cout >> "High ELO is set to: " << highELO << endl; //Testing
	cout << "Choose the lowest ELO that you want to see: " << endl;
	cin >> lowELO;
	cout >> "Low ELO is set to: " << lowELO << endl; // Testing
}

//To get info from API later, will fill with code for now
double GetWinChance(int p1ELO, int p2ELO){
	return 1 / (1 + pow(10, ((p1ELO - P2ELO) / 400)));
}

//To get info from API later, will fill with code for now
double DeltaELO(int winnerELO, int lowerELO, int stocks){
	int winChance = GetWinChance(winnerELO, loserELO);
	const int kFactor = 32;
	return kFactor * (0.6 + (stocks / 10) - winChance);
}

//Public Methods:

//Takes in the two players who are plaing a match
void Controller::PlayGame(Player &p1, Player &p2){
	//TODO
	//Setup:
		//Calculate the chance of each player winning (From API)
		//USe above calculation with a random number and find a winner
		//Calculate the change in ELO using DeltaELO() (from API)
		//change the ELO and adjust the number of wins/losses accordingly for each player
}
//Accepts a width to set the collumns to
void Controller::PrintPlayers(int w){
	//May want to ask how the user wants the info sorted
		//Currently outputting in order added, standard map
	//Columns, may need to make bigger depending on number of wins
	cout << setw(w) << "Name" ;
	cout << setw(w) << "ELO" ;
	cout << setw(w) << "Wins" ;
	cout << setw(w) << "Losses" ;
	cout << setw(w) << "W/L" << endl;
	for(map<Player *, int>::iterator it = players.begin(); it != players.end(); it++){
		it->first->PrintInfo(w);
	}
}

//TODO
Controller::Controller(){}
//TODO
Controller::~Controller(){}