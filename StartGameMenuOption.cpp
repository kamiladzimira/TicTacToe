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
	Game game(3);
	game.startGame ();

}