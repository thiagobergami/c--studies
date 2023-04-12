#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

class Card
{
public:
    enum rank
    {
        ACE = 1,
        TWO,
        THREE,
        FOUR,
        FIVE,
        SIX,
        SEVEN,
        EIGHT,
        NINE,
        TEN,
        JACK,
        QUEEN,
        KING
    };

    enum suit
    {
        CLUBS,
        DIAMONDS,
        HEARTS,
        SPADES
    };

    // overloading << operator so can send Card Objecto sto standard output;
    friend ostream &operator<<(ostream &os, const Card &aCard);

    Card(rank r = ACE, suit s = SPADES, bool ifu = true);

    // return a value of a card;
    int GetValue() const;

    // flips a card; if face up, becomes face down and vice versa
    void Flip();

private:
    rank m_Rank;
    suit m_Suit;
    bool m_IsFaceUp;
};

Card::Card(rank r, suit s, bool ifu) : m_Rank(r), m_Suit(s), m_IsFaceUp(ifu) {}

int Card::GetValue() const
{
    // if a cards is face down, its value is 0
    int value = 0;
    if (m_IsFaceUp)
    {
        // value is number showing on card
        value = m_Rank;
        // value is 10 for face cards
        if (value > 10)
        {
            value = 10;
        }
    }
    return value;
}

void Card::Flip()
{
    m_IsFaceUp = !(m_IsFaceUp);
}