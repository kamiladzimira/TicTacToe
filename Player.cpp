#pragma once
#include "Player.h"
#include <iostream>
#include <string>
using namespace std;

Player::Player (string name, string sign)
{
	Player::name = name;
	Player::sign = sign;
};

string Player::getName ()
{
	return name;
};

string Player::getSign ()
{
	return sign;
};



