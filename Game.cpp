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
	cout << "Hi " << player.getName () << ", you play with sign: " << player.getSign () << "." << endl;
}

void Game::startGame ()
{
	cout << "\n\n\tTic Tac Toe\n\n";

	cout << endl;

	playerOne = getPlayerFromUser ("one");
	playerTwo = getPlayerFromUser ("two");
	system ("cls");

	displayGreeting (*playerOne);
	displayGreeting (*playerTwo);
	cout << endl;
	cout << "Let's start the game!" << endl;
	cout << endl << endl;
	playerChooices ();

}


void Game::displayBoard ()
{
	cout << "\n\n\tTic Tac Toe\n\n";

	cout << endl; cout << endl;
	string s = board[0][0];
	cout << "\t     |     |     " << endl;
	cout << "\t  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << endl;

	cout << "\t_____|_____|_____" << endl;
	cout << "\t     |     |     " << endl;

	cout << "\t  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << endl;

	cout << "\t_____|_____|_____" << endl;
	cout << "\t     |     |     " << endl;

	cout << "\t  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << endl;

	cout << "\t     |     |     \n" << endl << endl;
}

void Game::playerChooices ()
{
	int counter = 0;
	string fieldNumber;
	string playerSign;

	while (counter < 5)
	{

		displayBoard ();
		if (counter % 2 == 0)
		{
			cout << playerOne->getName () << "'s choice: " << endl;
			playerSign = playerOne->getSign ();
		}
		else
		{
			cout << playerTwo->getName () << "'s choice: " << endl;
			playerSign = playerTwo->getSign ();

		}
		counter++;

		cin >> fieldNumber;
		system ("cls");
	}
}

void Game::setSign (Player player, string fieldNumber)
{

}

bool Game::isPlayerWin (Player player)
{
	bool isCorrect1 = true;
	bool isCorrect2 = true;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i == j)
			{
				if (board[i][j] != player.getSign ())
				{
					isCorrect1 = false;
				}
			}
			if (i + j == size -1)
			{
				if (board[i][j] != player.getSign ())
				{
					isCorrect2 = false;
				}
			}
		}
	}
	return isCorrect1 || isCorrect2;
}


