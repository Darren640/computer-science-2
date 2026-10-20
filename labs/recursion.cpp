#include <iostream>
#include <string>
using namespace std;
class node{
    public:
    node* data;
    node* next;


};

bool isPalindrome(string word, int left, int right) // determines whether a lowercase word reads the same forwards and backwards
{
    if (left >= right) { 
        return true;
    }
    if (word[left] != word[right]) {
        return false; 
    }
    return isPalindrome(word, left + 1, right - 1);
}

void reverse(node* p)
{
    if(p == nullptr || p->next == nullptr)
    {
        return;
    }
    else
    {
        node* a = p->next;
        reverse(a->next);
        a->next->next = a;
        a->next = nullptr;
    }      
}
bool isNondecreasing(const vector<int>& values, int value)
{
    if (value >= values.size() - 1) {
        return true;
    }
    if (values[value] > values[value + 1])
    {
        return false;
    }
    return isNondecreasing(values, value + 1);
}
bool placeQueen(vector<int>& board, int row) {
    if (row == board.size()) {
        return true;
    }
    for (int col = 0; col < board.size(); col++) {
        bool safe = true;
        for (int i = 0; i < row; i++) {
            if (board[i] == col || abs(board[i] - col) == row - i) {
                safe = false;
                break;
            }
        }
        if (safe) {
            board[row] = col;
            if (placeQueen(board, row + 1)) {
                return true;
            }
        }
    }
    return false;
}
int main() {
    string word[3] = {"racecar", "level", "coding"};
    isNondecreasing(values, index);




