#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#include <string>
#include <map>
#include <string>

class Player;

const int BASEELO = 1200;

class Controller {
	int numPlayers;
	std::Map<Player *> players;
	int highELO;
	int lowELO;
	bool typeELO;
	//int GetNumPlayers();
	void SetNumPlayers();
	void SetTypeELO();
	//bool GetTypeELO();
	void SetHighLowELO(std::string loworhi);
	//int GetHighLowELO(std::string loworhi);
public:
	void PlayGame(Player &p1, Player &p2);
	void PrintPlayers();
	//Will need to connect to API later
	double GetWinChance(int p1ELO, int p2ELO);
	double DeltaELO(int winnerELO, int loserELO, int stocks);
};

#endif