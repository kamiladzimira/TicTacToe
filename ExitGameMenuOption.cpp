#pragma once
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include "MenuOption.h"
#include "ExitGameMenuOption.h"

using namespace std;

ExitGameMenuOption::ExitGameMenuOption (string label, string enterString, int index) : MenuOption (label, enterString, index)
{

}

void ExitGameMenuOption::ChooseOption ()
{
	exit (0);
}