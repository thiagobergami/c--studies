/* Pseudocode

Create a tamagotchi
While the player doesn't want to quit the game
    Present a menu of choices to the player
    If the player want to listen to the tamagotchi
        Make the tamagotchi talk
    if the player wants to feed the tamagotchi
        make the tamagotchi eat
    if the player wants to play with the tamagotchi
        make the tamagotchi player
*/

#include <iostream>

using namespace std;

class Tamagotchi
{
public:
    Tamagotchi(int hunger = 0, int bored = 0); // constructor
    void Talk();
    void Eat(int food = 4);
    void Play(int fun = 4);

private:
    int m_Hunger;
    int m_Bored;

    int GetMood() const;
    void PassTime(int time = 1);
};

Tamagotchi::Tamagotchi(int hunger, int bored) : m_Hunger(hunger), m_Bored(bored) {}

// Inlining a function means that the compiler replaces calls to the function with the function's code itself
inline int Tamagotchi::GetMood() const
{
    return (m_Hunger + m_Bored);
}

void Tamagotchi::PassTime(int time)
{
    m_Hunger += time;
    m_Bored += time;
}
void Tamagotchi::Talk()
{
    cout << "I'm feeling ";

    int mood = GetMood();
    if (mood > 15)
    {
        cout << "MAD!! \n";
    }
    else if (mood > 10)
    {
        cout << "Frustrated.\n";
    }
    else if (mood > 5)
    {
        cout << "Okay. \n";
    }
    else
    {
        cout << "happy.\n";
    }

    PassTime();
}

void Tamagotchi::Eat(int food)
{
    cout << "Brrruppppp \n";
    m_Hunger -= food;

    if (m_Hunger < 0)
    {
        m_Hunger = 0;
    }

    PassTime();
}

void Tamagotchi::Play(int fun)
{
    cout << "Wheeee \n";
    m_Bored -= fun;

    if (m_Bored < 0)
    {
        m_Bored = 0;
    }

    PassTime();
}

int main()
{
    Tamagotchi tamagotchi;
    tamagotchi.Talk();

    int choice;
    do
    {
        cout << "\nWelcome to Tamagotchi\n\n";
        cout << "0 - Quit" << endl;
        cout << "1 - Listen your Tamagotchi" << endl;
        cout << "2 - Feed" << endl;
        cout << "3 - Play" << endl;

        cout << "\nChoice: ";
        cin >> choice;

        switch (choice)
        {
        case 0:
            cout << "Good-bye.\n";
        case 1:
            tamagotchi.Talk();
            break;
        case 2:
            tamagotchi.Eat();
            break;
        case 3:
            tamagotchi.Play();
            break;
        default:
            cout << "\nInvalid number, choose again.\n";
        }
        
    } while (choice != 0);

    return 0;
}
