#pragma once
#include <iostream>
#include <string>

#include "Board.h"
#include "Game.h"
#include "BoardField.h"
#include "Menu.h"

using namespace std;

Board::Board (int size, Player* playerOne, Player* playerTwo)
{
	Board::size = size;
	Board::playerOne = playerOne;
	Board::playerTwo = playerTwo;

	boardFields = new BoardField * [size]; // NEW
	for (int i = 0; i < size; i++)
	{
		boardFields[i] = new BoardField[size]; // NEW
	}

	int value = 1;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			//int value = (j + 1) + (size * i);
			boardFields[i][j].fieldNumber = value;
			value++;
		}
	}
}

bool Board::isBoardFull ()
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (boardFields[i][j].sign.empty ())
			{
				return false;
			}
		}
	}
	return true;
}

void Board::displayBoard ()
{
	cout << "\n\tTic Tac Toe\n\n";

	cout << "Test1" << endl;

	int longestCellSize = getLongestCellSize ();
	cout << "Test2" << endl;
	longestCellSize += 2;

	printLine (' ', '|', longestCellSize);
	cout << endl;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			int currentCellContentSize = boardFields[i][j].getContent ().length ();

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
			cout << boardFields[i][j].getContent ();

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

int Board::getLongestCellSize ()
{
	int longestCellSize = to_string (boardFields[size - 1][size - 1].fieldNumber).length ();

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

void Board::printLine (char lineChar, char columnChar, int cellSize)
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

bool Board::tryToSetSign (string sign, int fieldNumber)
{
	if (fieldNumber > (size * size))
	{
		return false;
	}

	int i = (fieldNumber - 1) / size;
	int j = (fieldNumber - 1) % size;

	if (!boardFields[i][j].sign.empty ())
	{
		return false;
	}
	boardFields[i][j].sign = sign;

	return true;
}
