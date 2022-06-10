#include <iostream>
#include "MenuOption.h"
using namespace std;

class Menu
{
private:
public:
    void showMenu ()
    {
        cout << endl;
        cout << "********** MENU **********" << endl;
        cout << "1. Start Game" << endl;
        cout << "2. High Score" << endl;
        cout << "3. Exit" << endl;
        cout << "**************************" << endl;
        cout << endl;
    }
};