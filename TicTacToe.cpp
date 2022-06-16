#pragma once
#include <iostream>
#include "Menu.h"
using namespace std;

    int main ()
    {
        Menu menu = Menu::CreateMainMenu ();
        menu.runMenu ();
        return 1;
    }

