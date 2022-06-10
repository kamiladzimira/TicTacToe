#pragma once
#include <iostream>
#include "Menu.h"
#include "MenuOption.h"
using namespace std;

class GameManager
{
private:
public:
	void Start ()
	{
		cout << "Start game!" << endl;
		Menu menu;
		menu.showMenu ();
	};
};


