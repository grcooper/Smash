#ifndef __PLAYER_H__
#define __PLAYER_H__

class Player {
	int name;
	//Returns the wins/games played
	int RatioWL();
public:
	double ELO;
	double numWins;
	double numLosses;
	void PrintInfo(int w);
	Player(int name, double ELO);
	Player();
};

#endif