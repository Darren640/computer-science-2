#ifndef CONNECT4_H
#define CONNRCT4_4

class Connect4
{
    private:
    char** board;
    int rows;
    int columns;
    
    public:
    void DrawBoard();
    bool GameOver();
    char Winner();
    bool MakeMove(char piece, int column);

    Connect4();
    Connect4(int numRows, int NumColumns);

    int getAiMove();
    ~Connect4();
};

#endif