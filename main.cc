#include <iostream>
#include "player.h"
#include "controller.h"

using namespace std;

int main(void){
	cout <<"Welcome to the Smash API Tester!" << endl;
	cout << "Press enter to continue" << endl;
	string toContinue;
	getline(cin, toContinue);

	Controller c;

	char choice;
	while(true){
		cout << "Press [e] to make all the players play each other" << endl;
		cout << "Press [t] to play a tournament with all the players" << endl;
		cout << "Press [s] to sort the list by ELO and display the players" << endl;
		cout << "Press [x] to exit" << endl;
		cin >> choice;
		if(choice == 'e'){
			c.PlayAll();
		}
		else if (choice == 'r'){
			//All players play according to ELO
		}
		else if (choice == 't'){
			//All Players play in a tournament and announces the winner
			c.PlayTourney();
		}
		else if (choice == 's'){
			c.SortELO();
		}
		else if(choice == 'x'){
			break;
		}
		else {
			if(cin.eof()){
				break;
			}
			else {
				cin.clear();
				cin.ignore();
			}
		}
	}

	return 0;
}