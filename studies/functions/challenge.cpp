#include <iostream>
#include <vector>

using namespace std;

void print_screen()
{
    cout << "P - Print numbers;" << endl;
    cout << "A - Print numbers;" << endl;
    cout << "M - Print numbers;" << endl;
    cout << "S - Print numbers;" << endl;
    cout << "L - Print numbers;" << endl;
    cout << "Q - Quit;" << endl;
}

bool validate_input(char input)
{
    char valid_letter[]{'P', 'A', 'M', 'S', 'L', 'Q'};
    bool found = false;

    for (char letter : valid_letter)
    {
        if (input == letter)
        {
            found = true;
        }
    }

    if (found == false)
    {
        cout << "Invalid options. Try again" << endl;
    }

    return found;
}

void print_vector(vector<int> &vec)
{
    for (int number : vec)
    {
        cout << number << ", ";
    }
}

void append_vector(vector<int> &vec)
{

    int number{0};
    cout << "Enter the number you want append: ";
    cin >> number;

    vec.push_back(number);
    // return vec;
}

void mean_vector(vector<int> &vec)
{
    int sum{0};
    for (int number : vec)
    {
        sum += number;
    }
    cout << "The mean of the vector is: " << sum / vec.size() << endl;
}

void smallest_number(vector<int> &vec)
{
    int smallest = vec.at(0);
    for (int number : vec)
    {
        if (number < smallest)
        {
            smallest = number;
        }
    }
    cout << "The smallest number is: " << smallest << endl;
}

void largest_number(vector<int> &vec)
{
    int largest = vec.at(0);
    for (int number : vec)
    {
        if (number < largest)
        {
            largest = number;
        }
    }
    cout << "The largest number is: " << largest << endl;
}

void run_options(char input, vector<int> &vec)
{
    switch (input)
    {
    case 'P':
        print_vector(vec);
        cout << "\n";
        break;
    case 'A':
        append_vector(vec);
        cout << "\n";
        break;
    case 'M':
        mean_vector(vec);
        cout << "\n";
        break;
    case 'S':
        smallest_number(vec);
        cout << "\n";
        break;
    case 'L':
        largest_number(vec);
        cout << "\n";
        break;
    }
}

int main()
{
    char input{};
    bool valid_input{false};
    vector<int> vec{2, 2, 3, 1};
    do
    {
        print_screen();
        cout << "\nEnter your option here: ";
        cin >> input;
        /* 
        I only this validation, insted of using default in switch to avoid some message like
        "Invalid option" when the user type Q.
        The Q option it's going to enter in the default option and I don't want to the program
        print invalid message and next finish process.

        Of course, I can do a case 'Q' and only break.
        */
        valid_input = validate_input(input);
        if (valid_input == true)
        {
            run_options(input, vec);
        }

    } while (input != 'Q');
    cout << "Finish running" << endl;
}