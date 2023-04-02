
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

void drawHangman(int incorrectGuesses)
{

    vector<std::string> hangmanParts = {
        " _______",
        "|       |",
        "|       O",
        "|      /|\\",
        "|      / \\",
        "|",
        "|___",
    };

    for (int i = 0; i < incorrectGuesses; i++)
    {
        cout << hangmanParts[i] << endl;
    }
}

int generateRandomPosition(int max_limit)
{
    srand(time(nullptr));

    int random = rand() % max_limit;

    return random;
}

int main()
{
    const int MAX_WRONG = 8;

    vector<string> words{"simplesmente", "certeza", "senhora", "divertido", "estudar", "viajar", "amor", "bola", "casa", "dado", "elefante", "faca", "gato", "helicoptero", "iluminar", "jabuti", "kiwi", "limonada", "macaco", "navio", "ouro", "pato", "queijo", "roda", "sapato", "tigre", "uva", "vento", "xadrez", "yoga", "zebra"};

    int wrong = 0;

    int randomIndex = generateRandomPosition(words.size());

    const string SECRET_WORD = words[randomIndex];
    string used = "";
    string soFar(SECRET_WORD.size(), '-');
    cout << SECRET_WORD;
    cout << "Welcome to Hangman. Good Luck!" << endl;
    do
    {
        cout << "\nYou have " << (MAX_WRONG - wrong);
        cout << " incorrect guesses left. \n";
        cout << "\nYou've used the following letters:\n"
             << used << endl;
        drawHangman(wrong);
        cout << "\n"
             << soFar << endl;

        char guess;
        cout << "\nEnter your guess: ";
        cin >> guess;

        guess = tolower(guess); // make lowecase

        while (used.find(guess) != string::npos)
        {
            cout << "\nAlready guessed " << guess << endl;
            cout << "\nEnter your guess: ";
            cin >> guess;

            guess = tolower(guess);
        }

        used = used + guess + ", ";

        if (SECRET_WORD.find(guess) != string::npos)
        {
            cout << "Correct!";

            for (int i = 0; i < SECRET_WORD.size(); i++)
            {
                if (SECRET_WORD[i] == guess)
                {
                    soFar[i] = guess;
                }
            }
        }
        else
        {
            cout << "WRONG\n";
            wrong++;            
        }
        system("clear");
    } while ((wrong < MAX_WRONG) && (soFar != SECRET_WORD));

    if (wrong == MAX_WRONG)
    {
        cout << "\n\nGAME OVER!";
    }
    else
    {
        cout << " \n\nCONGRATULATIONS!";
    }

    cout << "\nThe word was " << SECRET_WORD << endl;

    return 0;
}