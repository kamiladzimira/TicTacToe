#pragma once
#include <iostream>

#include "Player.h"
#include "BoardField.h"

using namespace std;

class Board
{
private:
	int size;
	Player* playerOne;
	Player* playerTwo;
	void printLine (char lineChar, char columnChar, int cellSize);
	int getLongestCellSize ();
public:
	Board (int size, Player* playerOne, Player* playerTwo);
	BoardField** boardFields;
	void displayBoard ();
	bool isBoardFull ();
	bool tryToSetSign (string sign, int fieldNumber);
};


