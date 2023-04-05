#include <iostream>

using namespace std;

class Critter
{
public:
    static int s_Total;

    // m_Hunger(hunger) is a shorthand way to assign values to data members in a constructor.
    Critter(int hunger = 0) : m_Hunger(hunger)
    {
        cout << "A new critter has been born!" << endl;
        ++s_Total;
    }; // constructor prototype
    void Greet();
    // The const at the end indicates that the function it's read only
    int GetHunger() const;
    void SetHunter(int hunger);
    static int GetTotal();

private:
    int m_Hunger;
};

int Critter::s_Total = 0;

int Critter::GetTotal()
{
    return s_Total;
}

int Critter::GetHunger() const
{
    return m_Hunger;
}

void Critter::SetHunter(int hunger)
{
    if (hunger < 0)
    {
        cout << "Invalid number";
    }
    else
    {
        m_Hunger = hunger;
    }
}

int main()
{
    cout << "\bStatic Member\n\n";

    cout << "The total number of critter is: ";
    cout << Critter::s_Total << "\n\n";

    Critter crit1, crit2, crit3;

    cout << "\nThe total number of critters is: ";
    cout << Critter::GetTotal() << "\n";

    cout << "Acess static number from object: ";
    cout << crit1.s_Total << "\n\n";

    cout
        << "---------------------------------------------------"
        << endl;
    Critter crit(7);
    cout << "Calling GetHunter() " << crit.GetHunger() << "\n\n";

    cout << "Calling SetHunger() with 9.\n\n";
    crit.SetHunter(9);
    cout << "Calling GetHunter() " << crit.GetHunger() << "\n\n";

    return 0;
}