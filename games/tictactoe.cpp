#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// global constants
const char X = 'X';
const char O = 'O';
const char EMPTY = ' ';
const char TIE = 'T';
const char NO_ONE = 'N';

// functions prototypes
void instructions();
void displayBoard(const vector<char> &board);
char askPlayer(string question);
char opponent(char piece);
char humanPiece();
char winner(const vector<char> &board);
inline bool isLegal(int move, const vector<char> &board);
int askNumber(string question, int high, int low);
int playerMove(const vector<char> &board, char human);
int computerMove(vector<char> board, char computer);
void announceWinner(char winner, char computer, char human);

int main()
{
    int move;
    const int NUM_SQUARES = 9;
    vector<char> board(NUM_SQUARES, EMPTY);
    instructions();
    displayBoard(board);

    char humanPlayer = humanPiece();
    char computerPlayer = opponent(humanPlayer);
    char turn = X;    

    while (winner(board) == NO_ONE)
    {
        if (turn == humanPlayer)
        {
            move = playerMove(board, humanPlayer);
            board[move] = humanPlayer;
        }
        else
        {
            move = computerMove(board, computerPlayer);
            board[move] = computerPlayer;
        }
        system("clear");
        displayBoard(board);
        turn = opponent(turn);
    }
    announceWinner(winner(board), computerPlayer, humanPlayer);
    return 0;
}

void announceWinner(char winner, char computer, char human)
{
    if (winner == TIE)
    {
        cout << "It's a tie\n";
    }
    else
    {
        cout << winner << "'s won!\n";
    }
}

void instructions()
{
    cout << "Welcome to Tic-Tac-Toe.\n";
    cout << "In this game you gonna face a computer mind to the title of master in Tic-Tac-Toe \n";

    cout << "Make your move know by entering a number, 0 -8. The number\n";
    cout << "cirresponds to the desired board position, as  illustrated\n\n";

    cout << " 0 | 1 | 2  \n";
    cout << "----------- \n";
    cout << " 3 | 4 | 5  \n";
    cout << "----------- \n";
    cout << " 6 | 7 | 8  \n\n";
    cout << "-------------------------- \n";
}

char winner(const vector<char> &board)
{
    // the vector passed in this function it not copied. It also means that the vector is safeguarded against any change.
    const int WINNING_ROWS[8][3] = {{0, 1, 2},
                                    {3, 4, 5},
                                    {6, 7, 8},
                                    {0, 3, 6},
                                    {1, 4, 7},
                                    {2, 5, 8},
                                    {0, 4, 8},
                                    {2, 4, 6}};

    const int TOTAL_ROWS = 8;

    for (int row = 0; row < TOTAL_ROWS; ++row)
    {
        if ((board[WINNING_ROWS[row][0]] != EMPTY) &&
            (board[WINNING_ROWS[row][0]] == board[WINNING_ROWS[row][1]]) &&
            (board[WINNING_ROWS[row][1]] == board[WINNING_ROWS[row][2]]))
        {
            return board[WINNING_ROWS[row][0]];
        }
    }

    if (count(board.begin(), board.end(), EMPTY) == 0)
        return TIE;

    return NO_ONE;
}

char opponent(char piece)
{
    if (piece == X)
    {
        return O;
    }
    else
    {
        return X;
    }
}

char askPlayer(string question)
{
    char response;
    do
    {
        cout << question << " (y/n): ";
        cin >> response;
    } while (response != 'y' && response != 'n');

    return response;
}

char humanPiece()
{
    char whoFirst = askPlayer("Do you require first move?");
    if (whoFirst == 'y')
    {
        cout << "\nThen take the first move. You will need it.\n";
        return X;
    }
    else
    {
        cout << "\nOk... I will go first\n";
        return O;
    }
}

void displayBoard(const vector<char> &board)
{
    cout << "\n"
         << board[0] << "  | " << board[1] << " | " << board[2];
    cout << "\n"
         << "-----------";
    cout << "\n"
         << board[3] << "  | " << board[4] << " | " << board[5];
    cout << "\n"
         << "-----------";
    cout << "\n"
         << board[6] << "  | " << board[7] << " | " << board[8];
    cout << "\n\n";
}

int askNumber(string question, int high, int low)
{
    int number;
    do
    {
        cout << question << " (" << low << " - " << high << "): ";
        cin >> number;
    } while (number > high || number < low);

    return number;
}

int playerMove(const vector<char> &board, char human)
{
    int move = askNumber("Make your move :", (board.size() - 1), 0);

    while (!isLegal(move, board))
    {
        cout << "\nThat square is already occupied \n";
        move = askNumber("Make your move :", (board.size() - 1), 0);
    }

    cout << "Fine... \n";
    return move;
}
int computerMove(vector<char> board, char computer)
{
    /*
    1 - if the computer can win on this move, make that move.
    2 - Otherwise, if the human can win on his next move, block him.
    3 - Otherwize, take the best remaining open square. The best square is
    the center. The nest best squares are the corners, en the rest of the squares
    */

    unsigned int move = 0; // only non-negatives numbers;
    bool found = false;

    // If computer can win on next move, that's the move to make
    while (!found && move < board.size())
    {
        if (isLegal(move, board))
        {
            board[move] = computer;
            found = winner(board) == computer;
            board[move] = EMPTY;
        }
        if (!found)
        {
            ++move;
        }
    }
    // Otherwise, if the human can win on his next move, block him.
    if (!found)
    {
        move = 0;
        char human = opponent(computer);

        while (!found && move < board.size())
        {
            if (isLegal(move, board))
            {
                board[move] = human;
                found = winner(board) == human;
                board[move] = EMPTY;
            }
            if (!found)
            {
                ++move;
            }
        }
    }

    // otherwise, moving to the best open square is the move to make
    if (!found)
    {
        move = 0;
        unsigned int i = 0;

        const int BEST_MOVES[] = {4, 0, 2, 6, 8, 1, 3, 5, 7};

        while (!found && i < board.size())
        {
            move = BEST_MOVES[i];
            if (isLegal(move, board))
            {
                found = true;
            }
            ++i;
        }
    }

    cout << "I shall take square number " << move << endl;

    return move;
}
inline bool isLegal(int move, const vector<char> &board)
{
    return (board[move] == EMPTY);
}