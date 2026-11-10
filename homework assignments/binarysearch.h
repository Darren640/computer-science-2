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
    node(double x) : data(x), left(nullptr), right(nullptr) {}
    
    friend class binarysearchTree;
};
class binarysearchTree
{
    private: 
        node* root;

    void insert(node*& p, double x) {
        if(p == nullptr) {
            p = new node(x);
            return;
        }
        if(x < p->data)
            insert(p->left, x);
        else if(x > p->data)
            insert(p->right, x);
    }
    void print(node* p)
    {
        if(p == nullptr)
            return;
        print(p->left);
        cout << p->data << " ";
        print(p->right);
    }
    void height(node* p, int& h)
    {
        if(p == nullptr)
            return;
        h++;
        height(p->left, h);
        height(p->right, h);
    }
    public:
    void insert(double x) {
        insert(root, x);
    }

    void print() {
        print(root);
    }

    int height() {
        int h = 0;
        height(root, h);
        return h;
    }
    binarysearchTree() : root(nullptr) {}
};
