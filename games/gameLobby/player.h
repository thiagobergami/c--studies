#ifndef PLAYER_H
#define PLAYER_H

#include <string>

using std::string;

class Player
{
public:
    Player(const string &name = "");
    string GetName() const;
    Player *GetNext() const;
    void SetNext(Player *next);

private:
    string m_Name;
    Player *m_pNext; // point to the next player in the list
};

#endif