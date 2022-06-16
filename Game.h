#pragma once
#include <iostream>
#include "Player.h"
#include "BoardField.h"

using namespace std;
class Game
{
private:
	BoardField** board;
	int size;
	Player* playerOne;
	Player* playerTwo;
	Player* getPlayerFromUser (string pt);
	void displayGreeting (Player player);
	bool isPlayerWon (Player player);
	bool tryToSetSign (string sign, int fieldNumber);
	int getLongestCellSize ();
	void printLine (char lineChar, char columnChar, int cellSize);
public:
	Game (int size);
	void displayBoard ();
	void startGame ();
	void runGameLoop ();
	bool isBoardFull ();
	
};


