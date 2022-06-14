#pragma once
#include <iostream>
#include "Menu.h"
#include "MenuOption.h"
#include "GameManager.h"
using namespace std;

class Menu;

	GameManager::GameManager ()
	{
	}
	// metoda wywolujaca metode showMenu z klasy Menu
	void GameManager::Start ()
	{
		Menu menu = Menu::CreateMainMenu ();
		menu.runMenu ();

		//MenuOption menuOption = menuOption;
		//menuOption.ChooseOption ();
	};



