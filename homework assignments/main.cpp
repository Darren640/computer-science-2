#include <iostream>
#include <Connect4.h>

using namespace std;

int main()
{
    cout << "Welcome to Connect4!!" << endl;
    int players;

    cout << "How many players? (1 or 2): ";
    cin >> players;

    Connect4* game;

    int choice;
    cout << "1. Standard 6x7 board" << endl;
    cout << "2. Custom board" << endl;
    cout << "Choice: ";
    cin >> choice;

    if(choice == 1)
    {
        game = new Connect4;
    }
    else
    {
         int rows;
        int columns;
        cout << "Enter number of rows: ";
        cin >> rows;

        cout << "Enter number of colunms: ";
        cin >> columns;

        game = new Connect4(rows, columns);
    }    
       

    
    char currentPlayer = 'X';

    while(!(*game).GameOver())
    {
        (*game).DrawBoard();
        cout << "It is " << currentPlayer << " 's turn." << endl;

        int column;

        if(players == 1 && currentPlayer == 'O')
        {
            column = (*game).getAiMove();

            cout << "AI chooses column: " << column << endl;
        }
        else
        {
            cout << "Column: ";
            cin >> column;
        }
        if(!(*game).MakeMove(currentPlayer, column))
        {
            cout << "Illegal move. Try again!" << endl;
            continue;
        }
        if((*game).Winner() != ' ')
        {
            (*game).DrawBoard();
            cout << "Player " << (*game).Winner() << " WINS" << endl;
            break;
        }
        if(currentPlayer == 'X')
        {
            currentPlayer == 'O';
        }
        else
        {
            currentPlayer = 'X';
        }
    }
    if((*game).Winner() ==  ' ')
    {
        (*game).DrawBoard();
        cout << "The game is a draw!!"<< endl;
    } 
    delete game;

    return 0;

}