#include "binarysearch.h"
#include <iostream>
using namespace std;

class binarysearchTree
{
    private:
        node* root; 
        
    void insert(node* &p, double x){
        
        if(p == nullptr) // base case 
        {
            p = new node(x);
            return;
        }
        else if(x < p->data)
        {
            insert(p->left, x);
        }
        else
        {
            insert(p->right, x);
        }
    }
    void print(node* p)
    {
        if(p == nullptr)
        {
        return;  
        }
        else
        {
                print(p->left);
                cout << p->data << " ";
                print(p->right);
        }
    }
    int height(node* p)
    {
        if(p == nullptr)
        {
            return 0; // height of empty tree
        }
        int leftHeight = height(p->left);
        int rightHeight = height(p->right);
        return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
    }
    
    public:
    binarysearchTree()
    {
        root = nullptr;
    }
    void insert(double x)
    {
        insert(root, x);
    }
    void print()
    {
        print(root);
    }
};