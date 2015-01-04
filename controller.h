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
	void SetNumPlayers();
	void SetTypeELO();
	void SetHighLowELO();
	int GetNumStocks(double winChance);
	//Will need to connect to API later
	double GetWinChance(int p1ELO, int p2ELO);
	double DeltaELO(int winnerELO, int loserELO, int stocks);
	void PlayGame(Player &p1, Player &p2);
	void Swap(int p1, int p2);
	int FindMax(int start);
public:
	void SortELO();
	void PlayAll();
	void PrintPlayers(int w);
	Controller();
	~Controller();
};

#endif