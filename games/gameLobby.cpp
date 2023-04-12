#include <iostream>
#include <string>
#include "gameLobby/player.h"
#include "gameLobby/lobby.h"

using namespace std;

int main()
{
    Lobby myLobby;
    int choice;

    do
    {
        cout << myLobby;
        cout << "\nGAME LOBBY\n";
        cout << "0 - Exit the program.\n";
        cout << "1 - Add a Player to the lobby.\n";
        cout << "2 - Remove a player from the lobby.\n";
        cout << "3 - Clear the Lobby.\n";
        cout << endl
             << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 0:
            cout << "Bye Bye.\n";
            break;
        case 1:
            myLobby.AddPlayer();
            break;
        case 2:
            myLobby.RemovePlayer();
            break;
        case 3:
            myLobby.Clear();
            break;
        default:
            cout << "That was not a valid choice.\n";
        }
        //system("clear");
    } while (choice != 0);

    return 0;
}