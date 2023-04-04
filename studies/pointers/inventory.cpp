/*
Understanding how works reference.
*/

#include <iostream>
#include <vector>

using namespace std;

void displayInventory(const vector<string> &inventory);
string *prtToElement(vector<string> *const pVec, int i);

int main()
{
    vector<string> inventory{"sword", "armor", "shield"};

    // displayer string object that the returned pointer points to
    cout << "Sending the objected pointed to by returned pointer:\n";
    cout << *(prtToElement(&inventory, 0)) << "\n\n";
    cout << "The memory address \n";
    cout << prtToElement(&inventory, 0) << "\n\n";

    // assigns one pointer to another -- inexpensive assignment
    cout << "Assigning the returned pointer to another pointer. \n";
    string *pStr = prtToElement(&inventory, 1);
    cout << "Sending the object pointed to by new pointer to cout: \n";
    cout << *pStr << "\n\n";

    // copies a string object -- expensive assignment
    cout << "Assigning object pointed by pointer to a string object. \n";
    string str = *(prtToElement(&inventory, 2));
    cout << "Sending\n";
    cout << str << "\n\n";

    // Altering the string object through a returned pointer
    cout << "Altering an object through a returned pointer. \n";
    *pStr = "Healing Potion";
    cout << "Sending\n";
    cout << inventory[1] << endl;

    return 0;
}
// By starting the header with string*, I'm saying that the function will return a pointer to a string object
string *prtToElement(vector<string> *const pVec, int i)
{
    // return address of the string in position i of vector that pVec points to
    return &((*pVec)[i]);
}
// This const reference protect the integrity of the vector
/* void displayInventory(const vector<string> &vec)
{
    for (string item : vec)
    {
        cout << item << endl;
    }
} */