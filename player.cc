#include <iostream>
#include <string>
#include <iomanip>
#include "player.h"

using namespace std;

Player::Player() : name(0), ELO(1200), numWins(0), numLosses(0){}
Player::Player(int name, int ELO) : name(name), ELO(ELO), numWins(0), numLosses(0){}

int Player::RatioWL(){
	if(numWins + numLosses == 0){
		return 0;
	}
	else {
		return numWins / (numWins + numLosses);
	}
}

void Player::PrintInfo(){
	cout << setw(10) << name;
	cout << setw(10) << ELO;
	cout << setw(10) << numWins;
	cout << setw(10) << numLosses;
	cout << setw(10) << RatioWL() << endl;
}