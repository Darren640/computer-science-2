#pragma once
#include <iostream>
#include <string>
using namespace std;
class linkedList
{
private:
    struct Node
    {
        string value;
        Node* next;

        explicit Node(const string& item) : value(item), next(nullptr) {}
    };

    Node* head;
    Node* tail;

public:
    linkedList() : head(nullptr), tail(nullptr) {}

    ~linkedList()
    {
        while (head != nullptr)
        {
            removeFront();
        }
    }

    linkedList(const linkedList&) = delete;
    linkedList& operator=(const linkedList&) = delete;

    void addFront(const string& item)
    {
        Node* newNode = new Node(item);
        (*newNode).next = head;
        head = newNode;

        if (tail == nullptr)
        {
            tail = newNode;
        }
    }

    void removeFront()
    {
        if (head == nullptr)
        {
            return;
        }
    
        Node* oldHead = head;
        head = (*head).next;
        delete oldHead;

        if (head == nullptr)
        {
            tail = nullptr;
        }
    }

    void addBack(const string& item)
    {
        Node* newNode = new Node(item);

        if (tail == nullptr)
        {
            head = tail = newNode;
            return;
        }

        (*tail).next = newNode;
        tail = newNode;
    }

    void remove(const string& item)
    {
        if (head == nullptr)
        {
            return;
        }

        if ((*head).value == item)
        {
            removeFront();
            return;
        }

        Node* current = head;
        while ((*current).next != nullptr && (*(*current).next).value != item)
        {
            current = current->next;
        }

        if ((*current).next != nullptr)
        {
            Node* nodeToDelete = (*current).next;
            ( (*current).next = (*nodeToDelete).next );

            if (nodeToDelete == tail)
            {
                tail = current;
            }

            delete nodeToDelete;
        }
    }

    void display() const
    {
        for (Node* current = head; current != nullptr; current = ((*current).next))
        {
            cout << current->value;
            if (current->next != nullptr)
            {
                cout << ' ';
            }
        }
        cout << '\n';
    }

    void sort()
    {
        for (Node* i = head; i != nullptr; i = ((*i).next))
        {
            for (Node* j = ((*i).next); j != nullptr; j = ((*j).next))
            {
                if ((*i).value > ((*j).value))
                {
                    string temp = (*i).value;
                    (*i).value = (*j).value;
                    (*j).value = temp;
                }
            }
        }
    }
};