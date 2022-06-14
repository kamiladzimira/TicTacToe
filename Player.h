#pragma once
#include <iostream>
using namespace std;

class Player
{
private:
	string name;
	string sign;

public:
	Player(string name, string sign);
	string getName ();
	string getSign ();
};


