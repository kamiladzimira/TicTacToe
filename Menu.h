#pragma once
#include <iostream>
#include <list>
#include "MenuOption.h"
using namespace std;
class Menu
{
private:
    list<MenuOption*> options;
public:
    Menu (list<MenuOption*> options);

    void showMenu ();

    static Menu CreateMainMenu ();
    static Menu CreateOptionsMenu ();
};

