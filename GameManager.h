#pragma once
#include <iostream>
#include "Menu.h"
#include "MenuOption.h"
using namespace std;

class GameManager
{
private:
public:

	// metoda wywolujaca metode showMenu z klasy Menu
	void Start ()
	{
		Menu menu = Menu::CreateMainMenu ();		
		menu.showMenu ();
	};
};


