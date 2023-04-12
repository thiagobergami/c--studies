#ifndef LOBBY_H
#define LOBBY_H

#include <iostream>
#include "player.h"

using std::ostream;

class Lobby
{
    friend ostream &operator<<(ostream &os, const Lobby &aLobby);

public:
    Lobby();
    ~Lobby();
    void AddPlayer();
    void RemovePlayer();
    void Clear();

private:
    Player *m_pHead; // Using aggregration 
};

#endif