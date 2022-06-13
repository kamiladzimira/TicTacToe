#pragma once
#include <iostream>
#include "MenuOption.h"
#include "Menu.h"
#include "HighScoreMenuOption.h"

using namespace std;

HighScoreMenuOption::HighScoreMenuOption (string label, string enterString, int index) : MenuOption (label, enterString, index)
{

}

void HighScoreMenuOption::ChooseOption ()
{
	Menu menu = Menu::CreateOptionsMenu ();
	menu.showMenu ();
}