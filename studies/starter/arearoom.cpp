#include <iostream>

using namespace std;

int main()
{
    int width{0};
    int height{0};

    cout << "Enter the width the room: ";
    cin >> width;

    cout << "Enter the height the room: ";
    cin >> height;

    cout << "The area of the room is: " << width * height << " m²" << endl;

    return 0;
}