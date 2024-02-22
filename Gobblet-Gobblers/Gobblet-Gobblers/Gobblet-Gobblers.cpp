// Gobblet-Gobblers._var1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Joc.h"

using namespace std;


int main()
{
    Joc GobbletGobblers;
    int nr_jucatori, ok = 1;

    cout << "Cate persoane vor juca? Doi jucatori sau un jucator? Alegeti : ";
    cin >> nr_jucatori;

    if (nr_jucatori != 1 && nr_jucatori != 2)
    {
        do
        {
            cout << "Nu exista varianta aleasa. Numarul de jucatori poate fi 1 sau 2. Alegeti varianta dorita : ";
            cin >> nr_jucatori;
            cout << endl;
            if (nr_jucatori == 1 || nr_jucatori == 2) ok = 1;
        } while (!ok);
    }

    if (nr_jucatori == 2) //player vs player
    {
        GobbletGobblers.player_vs_player();
    }
    else if (nr_jucatori == 1) // player vs computer
    {
        GobbletGobblers.player_vs_computer();
    }
    return 0;
}

