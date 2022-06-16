#pragma once
#include <iostream>
#include "Player.h"
#include "BoardField.h"

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

	BoardField** board;
	int size;
	Player* playerOne;
	Player* playerTwo;
	Player* getPlayerFromUser (string pt);
	void displayGreeting (Player player);
	bool isPlayerWon (Player player);
	bool tryToSetSign (string sign, int fieldNumber);
public:
	Game (int size);
	void displayBoard ();
	void startGame ();
	void playerChooices ();
	bool isBoardFull ();
	
};


