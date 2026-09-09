#include <iostream>
#include <string> // Used to be able to use string
#include <random>  // Gives access to even better random number generators, if you want
#include <chrono>  // Used to measure the execution time of the algorithm

using namespace std;

/*Hand in:
Turn in the following files to brightspace:
-Your .cpp solution
-A file with your analysis of how many steps your algorithm will take to guess a number from 1 to 1,000,000.
						
HiLo Guessing Game
 
This assignment utilizes:
- random numbers
- loops
- conditional statements
- basic I/O
- binary search
 

In the first HiLow assignment, the program created the random number and the user tried to guess it.  For this assignment, we swap roles:  The program will guess the user’s secret number.

Write a program to play the Hi-Lo guessing game.  In particular, your program should:
•	Ask the user to enter a positive integer (we will call this number n).
•	Ask the user to write down a number of their choice between 1 and n with pencil on a sheet of paper.
•	Next, the program should guess a number.  If incorrect, the user must tell the program if the guess is “too high” or “too low”, and then the program should guess again, repeating this process until the program correctly guesses the user’s number.
•	State the total number of guesses the program took to get the answer.
•	For n = 100, make sure your program will never take more than 10 guesses to get the correct answer.
•	For n = 1,000,000 , analyze the maximum possible number of guesses your program will take to get the correct answer.  Explain/justify your answer.
Here is a sample run where the text prefixed with "(user)" is the user entered data
*/
int main()
{
    int n;

    cout << "Enter a postive number: " << endl;
      cin >> n;
    cout << "Write down a number between 1 and " << n << " with pencil on a sheet of paper." << endl;

    int low = 1;
    int high = n;
    int guess;
    int numGuesses = 0;

    auto start = chrono::high_resolution_clock::now();
    while (low <= high)
    {
        guess = low + (high - low) / 2;
        numGuesses++;
        cout << "Is your number " << guess << "? (Enter 'y' for yes, 'h' for too high, 'l' for too low): " << endl;
        char response;
        cin >> response;
        if (response == 'y') {
            cout << "The program guessed your number in " << numGuesses << " guesses!" << endl;
            break;
        } else if (response == 'h') {
            high = guess - 1;
        } else if (response == 'l') {
            low = guess + 1;
        }
    }
    


    //method to time...
    auto finish = chrono::high_resolution_clock::now();

chrono::duration<double> elapsed = finish - start;
cout << "Algorithm took: " << elapsed.count() << endl;








}
