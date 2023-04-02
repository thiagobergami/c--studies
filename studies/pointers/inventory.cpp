/*
Understanding how works reference.
*/

#include <iostream>
#include <vector>

using namespace std;

void displayInventory(const vector<string> &inventory);

int main()
{
    vector<string> inventory{"sword", "armor", "shield"};

    displayInventory(inventory);

    return 0;
}
//This const reference protect the integrity of the vector
void displayInventory(const vector<string> &vec)
{
    for (string item : vec)
    {
        cout << item << endl;
    }
}