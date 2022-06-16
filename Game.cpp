#pragma once
#include <iostream>
#include "Game.h"
#include <string>
#include "Player.h"
#include "BoardField.h"
#include "Menu.h"
using namespace std;

Game::Game (int size)
{
	Game::size = size;

	board = new BoardField * [size];
	for (int i = 0; i < size; i++)
	{
		board[i] = new BoardField[size];
	}

	int value = 1;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			//int value = (j + 1) + (size * i);
			board[i][j].fieldNumber = value;
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

bool Game::isBoardFull ()
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (board[i][j].sign.empty ())
			{
				return false;
			}
		}
	}
	return true;

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
	runGameLoop ();

}

void Game::displayBoard ()
{
	cout << "\n\tTic Tac Toe\n\n";

	int longestCellSize = getLongestCellSize ();
	longestCellSize += 2;

	printLine (' ', '|', longestCellSize);
	cout << endl;
	
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			int currentCellContentSize = board[i][j].getContent ().length();

			int numberOfSpaces = longestCellSize - currentCellContentSize;

			int numberOfSpacesEachSide = numberOfSpaces / 2;
			if (numberOfSpaces % 2 == 1)
			{
				numberOfSpacesEachSide += 1;
			}

			for (int i = 0; i < numberOfSpacesEachSide; i++)
			{
				cout << " ";
			}
			if (numberOfSpaces % 2 == 0)
			{
				cout << " ";
			}
			cout << board[i][j].getContent ();

			for (int i = 0; i < numberOfSpacesEachSide; i++)
			{
				cout << " ";
			}
			if (j < size - 1)
			{
				cout << "|";
			}
		}
		cout << endl;
		printLine (' ', '|', longestCellSize);
		cout << endl;
		if (i < size - 1)
		{
			printLine ('-', '|', longestCellSize);
			cout << endl;
			printLine (' ', '|', longestCellSize);
			cout << endl;
		}
	}
}

void Game::printLine (char lineChar, char columnChar,int cellSize)
{
	for (int k = 0; k < size; k++)
	{
		for (int i = 0; i < cellSize + 1; i++)
		{
			cout << lineChar;
		}
		if (k < size - 1)
		{
			cout << columnChar;
		}
	}
}

int Game::getLongestCellSize ()
{
	int longestCellSize = to_string (board[size - 1][size - 1].fieldNumber).length ();

	if (playerOne->getSign ().length () > longestCellSize)
	{
		longestCellSize = playerOne->getSign ().length ();
	}

	if (playerTwo->getSign ().length () > longestCellSize)
	{
		longestCellSize = playerTwo->getSign ().length ();
	}
	return longestCellSize;
}

void Game::runGameLoop ()
{
	int counter = 0;
	int fieldNumber;
	string playerSign;
	bool isPlayerOneWon = false;
	bool isPlayerTwoWon = false;

	while (!isPlayerOneWon && !isPlayerTwoWon && !isBoardFull())
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

		if (cin >> fieldNumber)
		{
			if (tryToSetSign (playerSign, fieldNumber))
			{
				isPlayerOneWon = isPlayerWon (*playerOne);
				isPlayerTwoWon = isPlayerWon (*playerTwo);
				counter++;
			}
		}
		else
		{
			cin.clear ();
			cin.ignore (40, '\n');
		}
		system ("cls");


	}
	Player* winner = NULL;
	if (isPlayerOneWon)
	{
		winner = playerOne;
	}
	else if(isPlayerTwoWon)
	{
		winner = playerTwo;
	}
	if (winner != NULL)
	{
		cout << "Player " << winner->getName () << " won!" << endl;
	}
	else
	{
		cout << "Nobody won :(" << endl;
	}
	cout << endl;
	Menu menu = Menu::CreateEndGameMenu ();
	menu.runMenu ();
}

bool Game::tryToSetSign (string sign, int fieldNumber)
{
	if (fieldNumber > (size*size))
	{
		return false;
	}

	int i = (fieldNumber - 1) / size;
	int j = (fieldNumber - 1) % size;

	if (!board[i][j].sign.empty())
	{
		return false;
	}

	board[i][j].sign = sign;

	return true;
}

bool Game::isPlayerWon (Player player)
{
	bool isDiagonalCorrect1 = true;
	bool isDiagonalCorrect2 = true;
	bool* areRowsCorrect = new bool[size];
	bool* areColumnsCorrect = new bool[size];

	for (int i = 0; i < size; i++)
	{
		areRowsCorrect[i] = true;
		areColumnsCorrect[i] = true;
	}


	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i == j)
			{
				if (board[i][j].sign != player.getSign ())
				{
					isDiagonalCorrect1 = false;
				}
			}
			if (i + j == size - 1)
			{
				if (board[i][j].sign != player.getSign ())
				{
					isDiagonalCorrect2 = false;
				}
			}
			if (board[i][j].sign != player.getSign())
			{
				areRowsCorrect[i] = false;
				areColumnsCorrect[j] = false;
			}

		}
	}

	for (int i = 0; i < size; i++)
	{
		if (areRowsCorrect[i] || areColumnsCorrect[i])
		{
			return true;
		}
	}

	return isDiagonalCorrect1 || isDiagonalCorrect2; 
}

