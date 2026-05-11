#include <iostream>
using namespace std;

char board[3][3];
char currentPlayer;

void initializeBoard()
{
    char position = '1';

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            board[i][j] = position++;
        }
    }
}

void displayBoard()
{
    cout << "\n";

    for(int i = 0; i < 3; i++)
    {
        cout << " ";

        for(int j = 0; j < 3; j++)
        {
            cout << board[i][j];

            if(j < 2)
                cout << " | ";
        }

        cout << "\n";

        if(i < 2)
            cout << "---|---|---\n";
    }

    cout << "\n";
}

bool checkWin()
{
    // Row Check
    for(int i = 0; i < 3; i++)
    {
        if(board[i][0] == board[i][1] &&
           board[i][1] == board[i][2])
        {
            return true;
        }
    }

    // Column Check
    for(int i = 0; i < 3; i++)
    {
        if(board[0][i] == board[1][i] &&
           board[1][i] == board[2][i])
        {
            return true;
        }
    }

    // Diagonal Check
    if(board[0][0] == board[1][1] &&
       board[1][1] == board[2][2])
    {
        return true;
    }

    if(board[0][2] == board[1][1] &&
       board[1][1] == board[2][0])
    {
        return true;
    }

    return false;
}

bool checkDraw()
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(board[i][j] != 'X' &&
               board[i][j] != 'O')
            {
                return false;
            }
        }
    }

    return true;
}

void makeMove()
{
    int choice;
    bool validMove = false;

    while(!validMove)
    {
        cout << "Player " << currentPlayer
             << ", enter position (1-9): ";
        cin >> choice;

        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;

        if(choice >= 1 && choice <= 9 &&
           board[row][col] != 'X' &&
           board[row][col] != 'O')
        {
            board[row][col] = currentPlayer;
            validMove = true;
        }
        else
        {
            cout << "Invalid Move! Try Again.\n";
        }
    }
}

void switchPlayer()
{
    if(currentPlayer == 'X')
        currentPlayer = 'O';
    else
        currentPlayer = 'X';
}

int main()
{
    char replay;

    do
    {
        initializeBoard();
        currentPlayer = 'X';

        bool gameOver = false;

        while(!gameOver)
        {
            displayBoard();
            makeMove();

            if(checkWin())
            {
                displayBoard();
                cout << "Player "
                     << currentPlayer
                     << " Wins!\n";

                gameOver = true;
            }
            else if(checkDraw())
            {
                displayBoard();
                cout << "Game Draw!\n";

                gameOver = true;
            }
            else
            {
                switchPlayer();
            }
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> replay;

    } while(replay == 'y' || replay == 'Y');

    cout << "Thank You for Playing!\n";

    return 0;
}