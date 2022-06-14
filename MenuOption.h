#pragma once
#include <iostream>
#include <string> 
using namespace std;

class MenuOption
{
	private:
		string label;
		string enterString;
		int index;

	public:
		MenuOption (string label, string enterString, int index);
		string GetLabel ();
		string GetEnterString ();
		virtual void ChooseOption ();
};

