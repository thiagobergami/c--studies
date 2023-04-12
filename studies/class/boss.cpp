#include <iostream>
using namespace std;

class Enemy
{
public:
    Enemy();
    void virtual Attack() const; // made virtual to be overriden
    void virtual Taunt() const;  // made virtual to be overriden

protected:
    int m_Damage; // protected members can only be accessed by inheritance.
};

Enemy::Enemy() : m_Damage(10)
{
}

void Enemy::Taunt() const
{
    cout << "I'm gonna figth with you.\n";
}

void Enemy::Attack() const
{
    cout << "Attack inflicts " << m_Damage << " damage points!\n";
}

class Boss : public Enemy
{
public:
    Boss();
    void SpecialAttack() const;
    void virtual Taunt() const;
    void virtual Attack() const;

private:
    int m_DamageMultiplier;
};

Boss::Boss() : m_DamageMultiplier(3) {}

void Boss::Taunt() const
{
    cout << "The boss will smash you. \n";
}

void Boss::Attack() const
{
    Enemy::Attack();
    cout << " And Laughs.\n";
}

void Boss::SpecialAttack() const
{
    cout << "Special Attack inflicts " << (m_DamageMultiplier * m_Damage);
    cout << " damage points!\n";
}

int main()
{
    cout << "Creating an enemy.\n";
    Enemy enemy1;
    enemy1.Taunt();
    enemy1.Attack();

    cout << "\nCreating a boss.\n";
    Boss boss1;
    boss1.Taunt();
    boss1.Attack();
    boss1.SpecialAttack();

    return 0;
}