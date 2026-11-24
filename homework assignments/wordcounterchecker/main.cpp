#include "Counterchecker.h"
#include <fstream>
#include <iostream>
using namespace std;

int main()
    {
    ifstream inFile("story.txt");
	if (!inFile)
	{
		cout << "Could not open story.txt" << endl;
		return 1;
	}

	counterChecker T;
	string word;

	//>> reads one word at a time, skipping spaces and newlines
	while (inFile >> word)
	{
		T.insert(word);
	}
	inFile.close();

	ofstream outFile("wordCounts.txt");
	T.writeInOrder(outFile);
	outFile.close();

	cout << "Word counts written to wordCounts.txt" << endl;
	return 0;
    }