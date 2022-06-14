#pragma once
#include <iostream>
#include "MenuOption.h"
using namespace std;

class StartGameMenuOption : public MenuOption
{
public:
	StartGameMenuOption (string label, string enterString, int index);

	void ChooseOption ();
};
