#pragma once
#include <iostream>
#include "GameManager.h"

using namespace std;

    int main ()
    {
        //tworze konstruktor klasy gameManager i wywoluje z niej metode Start()
        GameManager gameManager;
        gameManager.Start ();
        system ("pause > 0");
        return 1;
    }

