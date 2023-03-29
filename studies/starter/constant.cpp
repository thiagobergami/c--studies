/*
Literal constants
\n - newline
\r - return
\t - tab
\b - backspace
\' - single quote
\" - double quote
\\ - backslash
*/

/*
Create a code that simulate a cleaning service
The cleaning service charges $30 per room
Sales tax rate is 6%
Estimates are valid for 30 days


Pseudoce:
    Prompt the user to enter the number of rooms
    Display the number of rooms
    Display price per room

    Total estimate:
*/

#include <iostream>

using namespace std;

struct Result {
    int cost;
    float cost_with_tax;
};

Result calculate_cost_fare(int rooms, int fare){
    const float tax{0.06};
    Result result;
    result.cost = rooms * fare;
    result.cost_with_tax = result.cost* tax;

    return result;
}

int main()
{
    const int large_fare{35};
    const int small_fare{25};

    int small_rooms{0};
    int large_rooms{0};

    cout << "Enter the number of small rooms: ";
    cin >> small_rooms;

    cout << "Enter the number of large rooms: ";
    cin >> large_rooms;

    Result small_result = calculate_cost_fare(small_rooms, small_fare);
    Result large_result = calculate_cost_fare(large_rooms, large_fare);

    int cost = small_result.cost + large_result.cost;
    float tax = small_result.cost_with_tax + large_result.cost_with_tax;

    cout << "Cost : $" << cost << endl;
    cout << "Tax : $" << tax << endl;
    cout << "Total estimate : $" << cost + tax << endl;

    return 0;
}

