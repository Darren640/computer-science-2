#include <iostream>
#include <stdexcept>
#include "Connect4.h"

using namespace std;

Connect4::Connect4()
{
    rows = 6;
    columns = 7;

    board = new char*[rows]{};
    for (int i = 0; i < rows; i++)
    {
        board[i] = new char[columns];
        for (int j = 0; j < columns; j++)
        {
            board[i][j] = ' ';
        }
    }
}

Connect4::Connect4(int NumRows, int NumColumns)
{
    if (NumRows <= 0 || NumColumns <= 0)
    {
        throw invalid_argument("Board dimensions must be positive!");
    }

    rows = NumRows;
    columns = NumColumns;

    board = new char*[rows]{};
    for (int i = 0; i < rows; i++)
    {
        board[i] = new char[columns];
        for (int j = 0; j < columns; j++)
        {
            board[i][j] = ' ';
        }
    }
}

void Connect4::DrawBoard()
{
    cout << "  ";
    for (int j = 0; j < columns; j++)
    {
        cout << j << ' ';
    }
    cout << endl;

    for (int i = 0; i < rows; i++)
    {
        cout << i << "|";
        for (int j = 0; j < columns; j++)
        {
            cout << board[i][j] << "|";
        }
        cout << endl;
    }

    cout << "  ";
    for (int j = 0; j < columns; j++)
    {
        cout << "--";
    }
    cout << "-" << endl;
}

bool Connect4::MakeMove(char piece, int column)
{
    if ((piece != 'X' && piece != 'O') ||
        column < 0 || column >= columns)
    {
        return false;
    }

    for (int i = rows - 1; i >= 0; i--)
    {
        if (board[i][column] == ' ')
        {
            board[i][column] = piece;
            return true;
        }
    }

    return false; // Column is full.
}

char Connect4::Winner()
{
    // Horizontal
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j <= columns - 4; j++)
        {
            char piece = board[i][j];
            if (piece != ' ' &&
                board[i][j + 1] == piece &&
                board[i][j + 2] == piece &&
                board[i][j + 3] == piece)
            {
                return piece;
            }
        }
    }

    // Vertical
    for (int i = 0; i <= rows - 4; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            char piece = board[i][j];
            if (piece != ' ' &&
                board[i + 1][j] == piece &&
                board[i + 2][j] == piece &&
                board[i + 3][j] == piece)
            {
                return piece;
            }
        }
    }

    // Diagonal down-right
    for (int i = 0; i <= rows - 4; i++)
    {
        for (int j = 0; j <= columns - 4; j++)
        {
            char piece = board[i][j];
            if (piece != ' ' &&
                board[i + 1][j + 1] == piece &&
                board[i + 2][j + 2] == piece &&
                board[i + 3][j + 3] == piece)
            {
                return piece;
            }
        }
    }

    // Diagonal up-right
    for (int i = 3; i < rows; i++)
    {
        for (int j = 0; j <= columns - 4; j++)
        {
            char piece = board[i][j];
            if (piece != ' ' &&
                board[i - 1][j + 1] == piece &&
                board[i - 2][j + 2] == piece &&
                board[i - 3][j + 3] == piece)
            {
                return piece;
            }
        }
    }

    return ' ';
}

bool Connect4::GameOver()
{
    if (Winner() != ' ')
    {
        return true;
    }

    for (int j = 0; j < columns; j++)
    {
        if (board[0][j] == ' ')
        {
            return false;
        }
    }

    return true; // The board is full: draw.
}

int Connect4::getAiMove()
{
    // Basic AI: choose the first column that is not full.
    for (int j = 0; j < columns; j++)
    {
        if (board[0][j] == ' ')
        {
            return j;
        }
    }

    return -1;
}

Connect4::~Connect4()
{
    for (int i = 0; i < rows; i++)
    {
        delete[] board[i];
    }
    delete[] board;
}