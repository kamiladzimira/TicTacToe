#pragma once
#include <iostream>
#include <string> 
using namespace std;

//klasa MenuOption, ktora ma 3 pola: label, czyli wyswietlany tekst do wyboru w menu, enterChar, czyli znak, ktory trzeba wpisac, zeby wybrac dany tekst oraz index, czyli int, ktory ma siê tylko wyswietlac przy opcjach.
class MenuOption
{
private:
	string label;
	string enterString;
	int index;

public:
	//tworze konstruktor MenuOptions
	MenuOption (string label, string enterString, int index)
	{
		MenuOption::label = label;
		MenuOption::enterString = enterString;
		MenuOption::index = index;
	}

	//metoda, ktora zwraca opcje zawarte w liscie MenuOption
	string GetLabel ()
	{
		return to_string(index) + ". " + label + "(" + enterString + ").";
	}

	string GetEnterString ()
	{
		return enterString;
	}

	void ChooseOption ()
	{

	}


};

