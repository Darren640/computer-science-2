#include <iosfwd>
#include <iostream>
using namespace std;
class node
{
private:
    double data;
    node* left;
    node* right;


public:
    node(double x) : data(x), left(nullptr), right(nullptr) 
    {

    }
    
    friend class binarysearchTree;
};

