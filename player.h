#ifndef __PLAYER_H__
#define __PLAYER_H__

class Player {
	int name;
	double ELO;
	double numWins;
	double numLosses;
	//Returns the wins/games played
	int RatioWL();
public:
	int GetName();
	double GetELO();
	double GetWins();
	double GetLosses();
	void WinGame(int deltaELO);
	void LoseGame(int deltaELO);
	void PrintInfo(int w);
	Player(int name, double ELO);
	Player();
};

#endif