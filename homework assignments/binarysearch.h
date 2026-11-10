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
       else
        { 
        print(p->left);
        cout << p->data << " ";
        print(p->right);
        }
       
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

    void displayTree(node* p, int indent = 0) {
        if(p == nullptr)
            return;
        displayTree(p->right, indent + 4);
        for(int i = 0; i < indent; i++)
            cout << " ";
        cout << p->data << endl;
        displayTree(p->left, indent + 4);
    }

    void displayTree() {
        displayTree(root);
    }

    void displayVertical(node* p, string prefix = "", bool isLeft = true) {
        if(p == nullptr)
            return;
        
        cout << prefix;
        cout << (isLeft ? "├── " : "└── ");
        cout << p->data << endl;
        
        if(p->left != nullptr || p->right != nullptr) {
            if(p->left != nullptr) {
                displayVertical(p->left, prefix + (isLeft ? "│   " : "    "), true);
            }
            if(p->right != nullptr) {
                displayVertical(p->right, prefix + (isLeft ? "│   " : "    "), false);
            }
        }
    }

    void displayVertical() {
        cout << root->data << endl;
        if(root->left != nullptr) {
            displayVertical(root->left, "", true);
        }
        if(root->right != nullptr) {
            displayVertical(root->right, "", false);
        }
    }

    int height() {
        int h = 0;
        height(root, h);
        return h;
    }
    binarysearchTree() : root(nullptr) {}
};
