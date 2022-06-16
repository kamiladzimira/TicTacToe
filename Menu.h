#pragma once
#include <iostream>
#include <list>
#include "MenuOption.h"
using namespace std;
class Menu
{
private:
	list<MenuOption*> options;
public:
	Menu (list<MenuOption*> options);

	void runMenu ();

	static Menu CreateMainMenu ();
	static Menu CreateOptionsMenu ();
	static Menu CreateEndGameMenu ();
};

