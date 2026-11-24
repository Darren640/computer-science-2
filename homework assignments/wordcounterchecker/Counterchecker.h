#pragma once
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class counterChecker
{   
    private:
	class node
	{
	public:
		string word;
		int count;
		node* left;
		node* right;

		node(string w)
		{
			word = w;
			count = 1;          //first time we see this word
			left = nullptr;
			right = nullptr;
		}
	};

	node* root;

	//add word w to the tree starting at p.
	//if w is already in the tree, just add 1 to its count.
	//p is a REFERENCE to the real pointer, so setting p changes the tree
	void insert(string w, node*& p)
	{
		if (p == nullptr)                //empty spot: new word
			p = new node(w);
		else if (w == p->word)           //already in the tree
			p->count++;
		else if (w < p->word)            //alphabetically smaller: go left
			insert(w, p->left);
		else                             //alphabetically bigger: go right
			insert(w, p->right);
	}

	//inorder traversal (left, ME, right) visits words in alphabetical order
	void writeInOrder(node* p, ofstream& out)
	{
		if (p == nullptr)
			return;
		writeInOrder(p->left, out);
		out << p->word << " " << p->count << endl;
		writeInOrder(p->right, out);
	}

	//delete every node: children first, then parent
	void clear(node* p)
	{
		if (p == nullptr)
			return;
		clear(p->left);
		clear(p->right);
		delete p;
	}

public:
	counterChecker()
	{
		root = nullptr;
	}

	~counterChecker()
	{
		clear(root);
	}

	void insert(string w)
	{
		insert(w, root);
	}

	void writeInOrder(ofstream& out)
	{
		writeInOrder(root, out);
	}
};

