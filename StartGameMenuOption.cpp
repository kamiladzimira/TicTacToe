#pragma once
#include <iostream>
#include "MenuOption.h"
#include "StartGameMenuOption.h"
#include "Game.h"
using namespace std;

StartGameMenuOption::StartGameMenuOption (string label, string enterString, int index) : MenuOption (label, enterString, index)
{

}

void StartGameMenuOption::ChooseOption ()
{
	int size;
	do
	{
		cin.clear ();
		cin.ignore (40, '\n');
		cout << "Choose size for board: ";

	} while (!(cin >> size));

	Game game(size);
	game.startGame ();

}