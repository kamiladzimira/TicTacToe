#pragma once
#include <iostream>

#include "Player.h"
#include "Board.h"

using namespace std;

class Game
{
private:
	Board* board;
	int size;
	Player* playerOne;
	Player* playerTwo;
	Player* getPlayerFromUser (string pt);
	void displayGreeting (Player player);
	bool isPlayerWon (Player player);
public:
	Game (int size);
	void startGame ();
	void runGameLoop ();	
};


