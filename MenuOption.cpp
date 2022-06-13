#pragma once
#include <iostream>
#include <string> 
#include "MenuOption.h"
#include "Menu.h"
using namespace std;


//klasa MenuOption, ktora ma 3 pola: label, czyli wyswietlany tekst do wyboru w menu, enterChar, czyli znak, ktory trzeba wpisac, zeby wybrac dany tekst oraz index, czyli int, ktory ma siê tylko wyswietlac przy opcjach.

	//tworze konstruktor MenuOptions
	MenuOption::MenuOption (string label, string enterString, int index)
	{
		MenuOption::label = label;
		MenuOption::enterString = enterString;
		MenuOption::index = index;
	}

	//metoda, ktora zwraca opcje zawarte w liscie MenuOption
	string MenuOption::GetLabel ()
	{
		return to_string (index) + ". " + label + "(" + enterString + ").";
	}

	string MenuOption::GetEnterString ()
	{
		return enterString;
	}

	void MenuOption::ChooseOption ()
	{
		Menu menu = Menu::CreateMainMenu();
		menu.showMenu ();
	}


