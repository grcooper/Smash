#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <time.h>
#include <math.h>
#include <vector>
#include "player.h"
#include "controller.h"

using namespace std;

const int BASE = 1200;
const int kFactor = 32;
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
	cout << "High ELO is set to: " << highELO << endl; //Testing
	cout << "Choose the lowest ELO that you want to see: " << endl;
	cin >> lowELO;
	cout << "Low ELO is set to: " << lowELO << endl; // Testing
}

int Controller::GetNumStocks(double winChance){
	//Solve kFactor * (0.6 + (stocks / 10) - winChance) == 0 for stocks
	int stocks = 10 * (winChance - 0.6);
	if(stocks < 1){
		return 1;
	}
	else {
		return stocks;
	}
}

//To get info from API later, will fill with code for now
double Controller::GetWinChance(int p1ELO, int p2ELO){
	return 1 / (1 + pow(10, ((p1ELO - p2ELO) / 400)));
}

//To get info from API later, will fill with code for now
double Controller::DeltaELO(int higherELO, int lowerELO, int stocks){
	int winChance = GetWinChance(higherELO, lowerELO);
	return kFactor * (0.6 + (stocks / 10) - winChance);
}

//Takes in the two players who are plaing a match
//Returns the name of the winner
int Controller::PlayGame(Player &p1, Player &p2){
	int delta;
	double winChance;
	//Currently the number of stocks that they won by is just random
	//This needs to be changed
	int numStocks;
	//Win chance is for the second player
	//ie 1400 vs 1000, 1400 has a 10/11 chance to win
	//We need to adjust based on the player with the higher/lower ELO
	if(p2.GetELO() > p1.GetELO()){
		winChance = GetWinChance(p2.GetELO(), p1.GetELO());
		int random = rand() % 101;
		numStocks = GetNumStocks(winChance);
		delta = DeltaELO(p2.GetELO(), p1.GetELO(), numStocks);
		if(random > (winChance * 100)){
			p2.WinGame(delta);
			p1.LoseGame(delta);
			return p2.GetName();
		}
		else {
			p1.WinGame(delta);
			p2.LoseGame(delta);
			return p1.GetName();
		}
	}
	else {
		winChance = GetWinChance(p1.GetELO(), p2.GetELO());
		int random = rand() % 101;
		numStocks = GetNumStocks(winChance);
		delta = DeltaELO(p1.GetELO(), p2.GetELO(), numStocks);
		if(random > (winChance * 100)){
			p1.WinGame(delta);
			p2.LoseGame(delta);
			return p1.GetName();
		}
		else {
			p2.WinGame(delta);
			p1.LoseGame(delta);
			return p2.GetName();
		}
	}
}

//SORTING using selection sort
void Controller::Swap(int p1, int p2){
	Player *tmp = players[p1];
	players[p1] = players[p2];
	players[p2] = tmp;
}

int Controller::FindMax(int start){
	int maxELO = players[start]->GetELO();
	int pos = start;
	for(int i = pos; i < numPlayers; i++){
		if(maxELO < players[i]->GetELO()){
			maxELO = players[i]->GetELO();
			pos = i;
		}
	}
	return pos;
}
void Controller::SortELO(){
	for(int i = 0; i < numPlayers; i++){
		int max = FindMax(i);
		Swap(i, max);
	}
	PrintPlayers(10);
}
//END OF SORTING

void Controller::PlayAll(){
	for(int i = 0; i < numPlayers - 1; i++){
		for(int q = (i + 1); q < numPlayers; q++){
			PlayGame(*players[i], *players[q]);
		}
	}
	PrintPlayers(10);
}

void Controller::PlayTourney(){
	//Sort players first so its not uneven
	SortELO();
	int tNumPlayers = numPlayers;
	if(numPlayers % 2 != 0){
		tNumPlayers--;
		cout << "There is an odd number of players so the lowest ELO player will not play" << endl;
	}
	int playNums[tNumPlayers];
	for(int i = 0; i < tNumPlayers; i++){
		playNums[i] = players[i]->GetName();
	}
	//Play until there is one player left
	while(tNumPlayers != 1){
		for(int q = 0; q < (tNumPlayers / 2); q++){
			int winner = PlayGame(*players[playNums[q * 2]], *players[playNums[(q * 2) + 1]]);
			playNums[q] = winner;
		}
		tNumPlayers = tNumPlayers / 2;
	}
	cout << "The Winner is Player: " << playNums[0] << endl;
	PrintPlayers(10);
}

void Controller::PlayByELO(){
	//Sort and play player next to you
	SortELO();
	for(int i = 0; i < (numPlayers / 2); i++){
		PlayGame(*players[i * 2], *players[(i * 2) + 1]);
	}
	PrintPlayers(10);
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
	for(int i = 0; i < numPlayers; i++){
		players[i]->PrintInfo(w);
	}
}

//Call all the methods above to create the controller with all the players
Controller::Controller(){
	//Random seed
	srand(time(0));
	//Num players setup
	SetNumPlayers();
	//Type of ELO setup
	players = new Player *[numPlayers];
	SetTypeELO();
	//Low and highELO setup
	if(randELO){
		SetHighLowELO();
	}
	else {
		highELO = BASE;
		lowELO = BASE;
	}
	//Set up all the players
	for(int i = 0; i < numPlayers; i++){
		//Get a random elo
		int tempRand;
		if(randELO){
			tempRand = rand() % highELO;
		}
		else {
			tempRand = 1200;
		}
		players[i] = new Player(i, tempRand);
	}
	PrintPlayers(10);
}
//Destroy the stack alloctated players and players array
Controller::~Controller(){
	for(int i = 0; i < numPlayers; i++){
		delete players[i];
	}
	delete[] players;
}


















