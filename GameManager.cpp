#pragma once
#include <iostream>
#include "Menu.h"
#include "MenuOption.h"
#include "GameManager.h"
using namespace std;

class Menu;

	// metoda wywolujaca metode showMenu z klasy Menu
	void GameManager::Start ()
	{
		Menu menu = Menu::CreateMainMenu ();
		menu.showMenu ();

		//MenuOption menuOption = menuOption;
		//menuOption.ChooseOption ();
	};



