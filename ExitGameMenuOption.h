#pragma once
#include <iostream>
#include "MenuOption.h"
using namespace std;


class ExitGameMenuOption : public MenuOption
{
public:
	ExitGameMenuOption (string label, string enterString, int index);

	void ChooseOption ();
};
