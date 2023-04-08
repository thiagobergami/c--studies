#include "critter.h"
#include <iostream>

using namespace std;

Critter::Critter(const string &name, int age)
{
    cout << "Constructor called\n";
    m_pName = new string(name);
    m_Age = age;
}
/*
When you have a class that allocates memory on the heap, you should write a desctructor that cleans up and frees that memory.
*/
Critter::~Critter()
{
    cout << "Destructor called\n";
    delete m_pName;
}

Critter::Critter(const Critter &c) // copy constructor prototype
{
    cout << "Copy Constructor called\n";
    m_pName = new string(*(c.m_pName));
    m_Age = c.m_Age;
}

Critter &Critter::operator=(const Critter &c) // overloaded assignment op def
{
    cout << "Overloaded Assignment Operator called\n";
    if (this != &c)
    {
        delete m_pName;
        m_pName = new string(*(c.m_pName));
        m_Age = c.m_Age;
    }

    return *this;
}

void Critter::Greet() const
{
    cout << "I'm " << *m_pName << " and I'm " << m_Age << " years old.\n";
    cout << "&m_pName: " << &m_pName << endl;
}
