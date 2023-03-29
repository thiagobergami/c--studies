/*

Write a program that asks the user to enter the following:
An integer representing the number of cents

You may assume that the number of cents entered is greater than or equal to zero

The program shoul then display how to provide that change to the user.

In the US:
    1 dollar is 100 cents
    1 quarter is 25 cents
    1 fime is 10 cents
    1 nickel is 5 cents
    1 penny is 1 cent.

Here is a sample run:

Enter an amount in cents: 92

Return
dollars :0
quarters:3
dimes   :1
nickels :2
pennies :2

*/

#include <iostream>

using namespace std;

int main()
{
    const int dollar{100};
    const int quarter{25};
    const int fime{10};
    const int nickel{5};
    const int penny{1};

    int cents{0};
    // this array could be a dictionary
    int money[5];

    cout << "Enter the amount of cents :";
    cin >> cents;

    // convert dolar value
    money[0] = cents / dollar;
    cents = cents % dollar;

    // quarter
    money[1] = cents / quarter;
    cents = cents % quarter;

    // fime
    money[2] = cents / fime;
    cents = cents % fime;

    // nickel
    money[3] = cents / nickel;
    cents = cents % nickel;

    // penny
    money[4] = cents / penny;
    cents = cents % penny;

    cout << "\nDollars:   " << money[0] << endl;
    cout << "Quarter:   " << money[1] << endl;
    cout << "Fime:      " << money[2] << endl;
    cout << "Nickel:    " << money[3] << endl;
    cout << "Penny:     " << money[4] << endl;
    return 0;
}