#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Connect4.h"

using namespace std;

Connect4::Connect4(int NumRows, int NumColumn)
{
    rows = NumRows;
    columns = NumColumn;

    board = new char*[rows];

    for(int i = 0; i < rows; i++)
    {
        board[i] = new char[columns];

        for(int j = 0; j < columns; j++)
        {
            board[i][j] = ' ';
        }
    }
}

void Connect4::DrawBoard()
{
    cout << " ";
    for(int j = 0; j < columns; j++)
    {
        cout << " " << endl;
    }
    cout << endl;
    for(int i = 0; i < rows; i++)
    {
        cout << i << "|";
        for(int j = 0; j < columns; j++)
        {
            cout << board[i][j] << "|";
        }
    }
    cout << endl;


    cout << " ";

    for(int j = 0; j < columns; j++)
    {
    cout << "--";
    }
    cout << "-" << endl;

}

bool Connect4::MakeMove(char piece, int column)
{
    if(column < 0 || column >= columns)
    {
        return false;
    }
    for(int i = rows - 1; i >= 0; i--)
    {
        if(board[i][column] == ' ')
        return true;
    }
return true;
}

char Connect4::Winner()
{
    //horizontal
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j <= columns - 4; j++)
        {
            char piece = board[i][j];

            if(piece != ' ' && board[i][j+1] == piece && board[i][j+2] == piece && board[i][j+3] == piece)
            {
                return piece;
            }
        }
    }
    //vertical
    for(int i = 0; i < rows - 4; i++)
    {
        for(int j = 0; j <= columns; j++)
        {
            char piece = board[i][j];
            
            if(piece != ' ' && board[i][j+1] == piece && board[i][j+2] == piece && board[i][j+3] == piece)
            {
                return piece;
            }
        }
    }
    //diagonal down right
    for(int i = 0; i < rows - 4; i++)
    {
        for(int j = 0; j < columns -4; j++)
        {
            char piece = board[i][j];

            if(piece != ' ' && board[i][j+1] == piece && board[i][j+2] == piece && board[i][j+3] == piece)
            {
                return piece;
            }
        }
    }
    //diagonal up right
    for(int i = 3; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            char piece = board[i][j];

            if(piece != ' ' && board[i][j+1] == piece && board[i][j+2] == piece && board[i][j+3] == piece)
            {
                return piece;
            }
        }
    }
    return ' ';
}
    bool Connect4::GameOver()
    {
        if(Winner() !=  ' ')
        {
            return true;
        }
        //check if board is full
        for(int j = 0; j < columns; j++)
        {
            if(board[0][j] == ' ')
            {
                return false;
            }
        }
         return true;
    }
   
    int Connect4::getAiMove()
    {
        for(int j = 0; j < columns; j++)
        {
            return j;
        }
        return -1;
    }
    Connect4::~Connect4()
    {
        for(int i = 0; i < rows; i++)
        {
            delete[] board[i];
        }
        delete[] board;
    }