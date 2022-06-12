#include <iostream>
#include <list>
using namespace std;

//przylaczam plik MenuOption, zeby moc go wykorzystac w tej klasie
#include "MenuOption.h"

class Menu
{
    //tworze prywatna liste typu MenuOption
private:
    list<MenuOption> options;
    
    //tworzê konstruktor dla Menu z lista typu MenuOption
public:
    Menu (list<MenuOption> options)
    {
        Menu::options = options;
    }

    // tworze metode, w ktorej iteruje po kazdym elemencie listy, zaczynajac od 1 elementu(begin) i iteruje dopoki i jest rozne od ostatniego elementu(end)
    // iterator zachowuje sie jak pointer na ten obiekt
    // nastepnie wywoluje metode GetLabel ze wzgledu na to, ze lista jest typu MenuOption, w ktorej jest metoda GetLabel
    void showMenu ()
    {
        for (std::list<MenuOption>::iterator i = options.begin(); i != options.end(); ++i)
        {            
                cout << i->GetLabel () << endl;
        }
        string input;
        cin >> input;

        for (std::list<MenuOption>::iterator i = options.begin (); i != options.end (); ++i)
        {
            if (i->GetEnterString () == input)
            {
                cout << i->GetLabel () << endl;
            }
        }
    }

    // NAJPRAWDOPODOBNIEJ tworze metode typu Menu. Tworze 3 zmienne typu MenuOption, ktore pozniej dodaje do listy
    //Wywoluje (posrednio) konstruktor menu
    static Menu CreateMainMenu ()
    {
        MenuOption startGame ("Start ", "s", 1);
        MenuOption highScore ("High Score ", "h", 2);
        MenuOption exitGame ("Exit ", "e", 3);

        list<MenuOption> menuOptions ({startGame, highScore, exitGame});

        Menu menu (menuOptions);
        cout << "Choose option: " <<endl;
        return menu;
    }
};
