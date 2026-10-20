#include <iostream>
#include <string>
using namespace std;
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

int main() {
    string word[3] = {"racecar", "level", "coding"};



