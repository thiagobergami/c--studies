#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Critter
{
public:
    Critter(const string &name = "");
    string GetName() const;

private:
    string m_Name;
};

Critter::Critter(const string &name) : m_Name(name){};

inline string Critter::GetName() const
{
    return m_Name;
}

class Farm
{
public:
    Farm(int spaces = 1);
    void Add(const Critter &aCritter);
    void RollCall() const;

private:
    vector<Critter> m_Critters;
};

Farm::Farm(int spaces)
{
    m_Critters.reserve(spaces);
}

void Farm::Add(const Critter &aCritter)
{
    m_Critters.push_back(aCritter);
}

void Farm::RollCall() const
{
    for (Critter animal : m_Critters)
    {   
        cout << animal.GetName() << ", here. \n";
    }
}

int main()
{
    Critter crit("Poochie");
    cout << "Critter name " << crit.GetName() << endl;

    cout << "\nCreating Farm" << endl;
    Farm myFarm(3);

    cout << "Adding 3 critters.\n";
    myFarm.Add(Critter("Moe"));
    myFarm.Add(Critter("Larry"));
    myFarm.Add(Critter("Tunico"));

    cout << "\nCalling Roll...\n";
    myFarm.RollCall();

    return 0;
}