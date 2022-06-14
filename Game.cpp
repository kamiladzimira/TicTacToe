#pragma once
#include <iostream>
#include "Game.h"
#include <string>
#include "Player.h"
using namespace std;

Game::Game (int size)
{
	board = new string * [size];
	for (int i = 0; i < size; i++)
	{
		board[i] = new string[size];
	}

	int value = 1;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			//int value = (j + 1) + (size * i);
			board[i][j] = to_string (value);
			value++;
		}
	}
}

Player* Game::getPlayerFromUser (string player)
{
	string name;
	string sign;

	cout << "Choose name for player " << player << ": " << endl;
	cin >> name;
	cout << "Choose sign to play for player " << player << ": " << endl;
	cin >> sign;

	return new Player (name, sign);
}

void Game::displayGreeting (Player player)
{
	cout << "Hi " << player.getName() << ", you play with sign: " << player.getSign() << "." << endl;
}

void Game::startGame ()
{
	cout << "\n\n\tTic Tac Toe\n\n";

	cout << endl;

	/*playerOne = getPlayerFromUser ("one");
	playerTwo = getPlayerFromUser ("two");
	system ("cls");

	displayGreeting (*playerOne);
	displayGreeting (*playerTwo);*/

	cout << endl;
	cout << "Let's start the game!" << endl;
	cout << endl << endl;
	
	displayBoard ();
}


void Game::displayBoard ()
{
	cout << "\n\n\tTic Tac Toe\n\n";

	cout << endl; cout << endl;
	string s = board[0][0];
	cout << "     |     |     " << endl;
	cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << endl;

	cout << "     |     |     " << endl
		<< endl;
}

