#ifndef __PLAYER_H__
#define __PLAYER_H__

class Player {
	int name;
	int ELO;
	int numWins;
	int numLosses;
	//Returns the wins/games played
	int RatioWL();
public:
	void PrintInfo();
	Player(int name, int ELO);
	Player();
};

#endif