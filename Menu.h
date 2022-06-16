#pragma once
#include <iostream>
#include <list>
#include "MenuOption.h"
using namespace std;
class Menu
{
private:
	string menuHeader;
	list<MenuOption*> options;
public:
	Menu (list<MenuOption*> options, string menuHeader);

	void runMenu ();

	static Menu CreateMainMenu ();
	static Menu CreateOptionsMenu ();
	static Menu CreateEndGameMenu ();
};

