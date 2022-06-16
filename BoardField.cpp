#pragma once
#include <iostream>
#include <string>
#include "BoardField.h"
using namespace std;

BoardField::BoardField ()
{

};

string BoardField::getContent ()
{
	if (sign.empty())
	{
		return to_string(fieldNumber);
	}
	return sign;
};
