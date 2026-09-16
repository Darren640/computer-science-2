#include <iostream>
#include <stack>
using namespace std;

int main() 
{
    stack<int> numbers;
    int u;
    cout << "Enter numbers to 5 numbers: ";
    for(int i = 0; i < 5; i++)
    {
        cin >> u;
        numbers.push(u);
    }
    cout << "Top value: " << numbers.top() << endl;

    for(int i = 0; i < 2; i++)
    {
        cout << "Popped value in loop: " << numbers.top() << endl;
        numbers.pop();
    }
    cout << "new top: " << numbers.top() << endl;
    while(!numbers.empty())
    {
        cout << numbers.top() << " ";
        numbers.pop();
    }
    return 0;
}