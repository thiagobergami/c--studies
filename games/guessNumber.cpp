#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

/*

Create a Guess a Number Game.

In Guess a number, the player has x atempts to try to guess the correct number. The code can only return if it less or greater than the mistery number

*/

class Difficulty
{
public:
    // constructor
    Difficulty(string name, int value)
    {
        this->name = name;
        this->value = value;
    }

    // Getter for difficulty name
    string getName()
    {
        return name;
    }

    int getValue()
    {
        return value;
    }

private:
    string name;
    int value;
};

void validateInput(int number, int input)
{
    if (input < number)
    {
        cout << "Sorry, your number is SMALLER than the mysterious" << endl;
    }
    else if (input > number)
    {
        cout << "Sorry, your number is GREATER than the mysterious" << endl;
    }
    else
    {
        cout << "Congratulations!! You nailed it :" << number << endl;
    }
};

int main()
{
    vector<Difficulty> difficulties;
    difficulties.push_back(Difficulty("EASY", 12));
    difficulties.push_back(Difficulty("MEDIUM", 8));
    difficulties.push_back(Difficulty("HARD", 6));

    srand(static_cast<unsigned int>(time(0))); // seed random number generator
    int randomNumber = rand();
    int answer = (randomNumber % 1000) + 1;
    char inputDifficult;

    cout << "Welcome to Guess a Number \n\n";
    cout << "Select a difficulty level:\n";
    for (int i = 0; i < difficulties.size(); i++)
    {
        cout << i + 1 << ". " << difficulties[i].getName() << " - " << difficulties[i].getValue() << " attempts" << endl;
    }
    int choice;
    cin >> choice;

    while (choice < 1 || choice > difficulties.size())
    {
        cout << "Invalid Choice. Try again \n";
        cin >> choice;
    }

    Difficulty chousenDifficulty = difficulties[choice - 1];
    int attempts = chousenDifficulty.getValue();
    cout << "Starting game on difficult " << chousenDifficulty.getName() << endl;
    cout << "The magic number is between 1 and 1000" << endl;
    int input;
    do
    {
        cout << "You have " << attempts << " attempts" << endl;
        cout << "Take a guess: ";
        cin >> input;
        validateInput(answer, input);
        attempts--;
    } while (answer != input && attempts != 0);

    if (answer != input && attempts == 0)
    {
        cout << "The mistery number is :" << answer << endl;
        cout << "GAME OVER!" << endl;
    }
}