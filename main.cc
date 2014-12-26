#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <math.h>
#include "player.h"

using namespace std;

const int BASEELO = 1200;

//Gets the number of players from the user
int GetNumPlayers(){
	cout << "How many players would you like to test for?" << endl;
	//TODO: ERROR CHECKING
	int numPlayers;
	cin >> numPlayers;
	return numPlayers;
}

//Gets the type of ELO from the user, ether random or standard
bool GetTypeELO(){
	cout << "Should the ELO be random or standard(1200)?\nType [r]andom or [s]tandard." << endl;
	//TODO: ERROR CHECKING
	char choice;
	cin >> choice;
	return (choice == 'r');
}

//Gets the high or low elo limits for the random generator
int GetHighLowELO(string loworhi){
	cout << "Choose the "<< loworhi << " ELO you want to see" << endl;
	int num;
	//TODO: ERROR CHECKING
	cin >> num;
	return num;
}
// function getWinChance(player, opponent) {
//   return 1 / (1 + Math.pow(10, ((opponent - player) / 400.0)));
// }
double GetWinChance(int p1ELO, int p2ELO){
	return 1 / (1 + pow(10, ((p1ELO - p2ELO) / 400)));
}

// function deltaElo(winner, loser, stocks) {
//   var winChance = getWinChance(winner, loser);
//   var Kfactor = 32;
//   return Kfactor * (0.6 + (stocks / 10) - winChance);
// }
double DeltaELO(int winnerELO, int loserELO, int stocks){
	int winChance = GetWinChance(winnerELO, loserELO);
	const int kFactor = 32;
	return kFactor * (0.6 + (stocks / 10) - winChance);
}


//The stocks right now are just random, this should be changed depending on ELO
void PlayGame(Player &p1, Player &p2){
	int winChance = (rand() % 2) + 1;
	//cout << "Win chance: " << winChance << endl;
	double winNum = rand();
	int numStocks = (rand() % 3) + 1;
	//cout << "numstocks: " << numStocks << endl;
	int change = 0;
	if(winChance == 1){
		change = DeltaELO(p1.ELO, p2.ELO, numStocks);
		//cout << "Change1: " << change << endl;
		p1.ELO += change;
		p1.numWins++;
		p2.ELO -= change;
		p2.numLosses++;
	}
	else{
		change = DeltaELO(p2.ELO, p1.ELO, numStocks);
		//cout << "Change1: " << change << endl;
		p2.ELO += change;
		p2.numWins++;
		p1.ELO -= change;
		p1.numLosses++;
	}
}

int main(void){
	srand(time(0));
	int numPlayers = GetNumPlayers();

	bool randELO = GetTypeELO();
	int highELO = BASEELO;
	int lowELO = BASEELO;
	if(randELO){
		highELO = GetHighLowELO("high");
		lowELO = GetHighLowELO("low");
	}

	//For now just do a round robin, but have a question if a the user wants
	//to test for a tournement

	//Set up the array of players
	Player *players = new Player[numPlayers];
	for(int i = 0; i < numPlayers; i++){
		int tempELO;
		if(randELO){
			tempELO = (rand() % (highELO - lowELO)) + lowELO;
		}
		else {
			tempELO = 1200;
		}
		//The name is the starting number in the array.
		Player tempP(i, tempELO);
		players[i] = tempP;
	}


	//print players
	//I want to eventually abstract this out into a function
	cout << setw(10) << "Name" ;
	cout << setw(10) << "ELO" ;
	cout << setw(10) << "Wins" ;
	cout << setw(10) << "Losses" ;
	cout << setw(10) << "W/L" << endl;
	for(int i = 0; i < numPlayers; i++){
		players[i].PrintInfo();
	}

	//every player plays every player:
	//We subtract one so we do not get the last player playing themselves or any other shenanigans
	for(int i = 0; i < numPlayers - 1; i++){
		for(int q = i + 1; q < numPlayers; q++){
			PlayGame(players[i], players[q]);
		}
	}

	//print players
	cout << setw(10) << "Name" ;
	cout << setw(10) << "ELO" ;
	cout << setw(10) << "Wins" ;
	cout << setw(10) << "Losses" ;
	cout << setw(10) << "W/L" << endl;
	for(int i = 0; i < numPlayers; i++){
		players[i].PrintInfo();
	}

	//Cleanup at the end
	delete[] players;
	return 0;
}