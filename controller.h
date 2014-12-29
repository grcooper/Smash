#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#include <string>
#include <map>
#include <string>

class Player;

const int BASEELO = 1200;

class Controller {
	int numPlayers;
	Player **players;
	int highELO;
	int lowELO;
	bool randELO;
	int stocks;	
	void SetNumPlayers();
	void SetTypeELO();
	void SetHighLowELO();
	void GetNumStocks();
	//Will need to connect to API later
	double GetWinChance(int p1ELO, int p2ELO);
	double DeltaELO(int winnerELO, int loserELO, int stocks);
public:
	void PlayGame(Player &p1, Player &p2);
	void PrintPlayers(int w);
	Controller();
	~Controller();
};

#endif