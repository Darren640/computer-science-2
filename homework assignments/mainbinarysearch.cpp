#include "binarysearch.h"
#include <iostream>
using namespace std;

int main()
{
     double num[10] = {13, 18, 46, 6, 4, 2, 7, 5, 17, 78};
    binarysearchTree tree;
    cout << "Inserting numbers into the tree..." << endl;
    for(int i = 0; i < 10; i++)
    {
        tree.insert(num[i]);
    }
    
    cout << "\nIn-order traversal: ";
    tree.print();
    cout << endl;
    
    cout << "\nTree Structure (Vertical):" << endl;
    tree.displayVertical();
    
    cout << "\nHeight of tree: " << tree.height() << endl;

}