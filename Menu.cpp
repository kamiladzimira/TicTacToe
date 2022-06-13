#pragma once
#include <iostream>
#include <list>
using namespace std;

//przylaczam plik MenuOption, zeby moc go wykorzystac w tej klasie
#include "MenuOption.h"
#include "HighScoreMenuOption.h"
#include "StartGameMenuOption.h"
#include "ExitGameMenuOption.h"
#include "Menu.h"

    Menu::Menu (list<MenuOption*> options)
    {
        Menu::options = options;
    }

    // tworze metode, w ktorej iteruje po kazdym elemencie listy, zaczynajac od 1 elementu(begin) i iteruje dopoki i jest rozne od ostatniego elementu(end)
    // iterator zachowuje sie jak pointer na ten obiekt
    // nastepnie wywoluje metode GetLabel ze wzgledu na to, ze lista jest typu MenuOption, w ktorej jest metoda GetLabel
    void Menu::showMenu ()
    {
        for (std::list<MenuOption*>::iterator i = options.begin (); i != options.end (); ++i)
        {
            cout << (*i)->GetLabel () << endl;
        }
        string input;
        cin >> input;

        for (std::list<MenuOption*>::iterator i = options.begin (); i != options.end (); ++i)
        {
            if ((*i)->GetEnterString () == input)
            {
                (*i)->ChooseOption ();
            }
        }
    }

    // NAJPRAWDOPODOBNIEJ tworze metode typu Menu. Tworze 3 zmienne typu MenuOption, ktore pozniej dodaje do listy
    //Wywoluje (posrednio) konstruktor menu
    Menu Menu::CreateMainMenu ()
    {
        StartGameMenuOption* startGame = new StartGameMenuOption ("Start ", "s", 1);
        HighScoreMenuOption* highScore = new HighScoreMenuOption ("High Score ", "h", 2);
        ExitGameMenuOption* exitGame = new ExitGameMenuOption ("Exit ", "e", 3);

        list<MenuOption*> menuOptions ({startGame, highScore, exitGame});

        Menu menu (menuOptions);
        cout << "Choose option: " << endl;
        return menu;
    }

    Menu Menu::CreateOptionsMenu ()
    {
        StartGameMenuOption* startGame = new StartGameMenuOption ("Start ", "s", 1);
        MenuOption* goBackToMenu = new MenuOption ("Go back to menu ", "g", 2);

        list<MenuOption*> menuOptions ({startGame, goBackToMenu});

        Menu menu (menuOptions);
        cout << "Choose option: " << endl;
        return menu;
    }

