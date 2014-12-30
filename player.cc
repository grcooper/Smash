#include <iostream>
#include <string>
#include <iomanip>
#include "player.h"

using namespace std;

Player::Player() : name(0), ELO(1200), numWins(0), numLosses(0){}
Player::Player(int name, double ELO) : name(name), ELO(ELO), numWins(0), numLosses(0){}

int Player::GetName(){
	return name;
}

double Player::GetELO(){
	return ELO;
}

double Player::GetWins(){
	return numWins;
}

double Player::GetLosses(){
	return numLosses;
}

void Player::WinGame(int deltaELO){
	numWins++;
	ELO += deltaELO;
}

void Player::LoseGame(int deltaELO){
	numLosses++;
	ELO -= deltaELO;
}

int Player::RatioWL(){
	if(numWins + numLosses == 0){
		return 0;
	}
	else {
		return (100 * (numWins / (numWins + numLosses)));
	}
}

//Takes in an input which is the width of hte collumns
void Player::PrintInfo(int w){
	cout << setw(w) << name;
	cout << setw(w) << ELO;
	cout << setw(w) << numWins;
	cout << setw(w) << numLosses;
	cout << setw(w) << RatioWL() << endl;
}