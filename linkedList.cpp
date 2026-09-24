#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

int main() {
    Node* head = nullptr;              // empty list

    // add 30, 20, 10 to the front → list becomes 10, 20, 30
    for (int val : {30, 20, 10}) {
        Node* n = new Node(val);
        n->next = head;
        head = n;
    }

    // print
    for (Node* cur = head; cur != nullptr; cur = cur->next)
        cout << cur->data << " -> ";
    cout << "nullptr\n";

    // free
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}
