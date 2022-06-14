#pragma once
#include <iostream>
#include "MenuOption.h"
using namespace std;

	class HighScoreMenuOption : public MenuOption
	{
	public:
		HighScoreMenuOption (string label, string enterString, int index);
		void ChooseOption ();
	};

