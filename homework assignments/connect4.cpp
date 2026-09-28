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
    for(int i = 0l i < rows; i++)
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
    
}