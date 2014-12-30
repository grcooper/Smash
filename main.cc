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
		cout << "Press [y] to make all the players play each other" << endl;
		//cout << "Press [s] to sort the list by ELO" << endl;
		cout << "Press [x] to exit" << endl;
		cin >> choice;
		if(choice == 'y'){
			c.PlayAll();
		}
		//else if (choice == 's'){
		//	c.SortELO();
		//}
		else  if(choice == 'x'){
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