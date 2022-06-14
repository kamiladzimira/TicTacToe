#pragma once
#include <iostream>
#include "Player.h"

using namespace std;
class Game
{
private:

	/*string** board[3][3] =
	{
		{"1", "2", "3"},
		{"4", "5", "6"},
		{"7", "8", "9"}
	};*/

	string** board;
	Player* playerOne;
	Player* playerTwo;
	Player* getPlayerFromUser (string pt);
	void displayGreeting (Player player);

public:
	Game (int size);
	void displayBoard ();
	void startGame ();
	void playerChooices ();
};


