#include <iostream>
#include <stack>
using namespace std;
class doublyLL
{
	// class definition goes here
    private:
    class node
    {
    public:
        double data;
        node* next;
        node* prev;
        node(double d) : data(d), next(nullptr), prev(nullptr) {}
    };
        private:
        node* head;
        node* tail;
        public:
        doublyLL()
        {
            head = nullptr;
            tail = nullptr;
        }
        double sum()
        {
            double total = 0;
            node* current = head;
            while (current != nullptr)
            {
                total += current->data;
                current = current->next;
            }
            return total;
        }
        double getMax()
        {
            if(head == nullptr)
            {
                return 0;
            }
            double max = head->data;
            node* current = head->next;
            while(current != nullptr)
            {
                if(current->data > max)
                {
                    max = current->data;
                }
                current = current->next;
            }
            return max;
        }
        int countOf(double x)
        {
            int count = 0;
            node* current = head;
            while (current != nullptr)
            {
                if(current->data == x)
                {
                    count++;
                }
                current = current->next;
            }
            return count;
        }
        double getAt(int i)
        {
            node* current = head;
            int count = 0;
            while (current != nullptr)
            {
                if (count == i)
                {
                    return current->data;
                }
                current = current->next;
                count++;
            }
            return 0; // or throw an exception if index is out of bounds

        }
        void removeFront()
        {
            if(head == nullptr)
            {
                return; // nothing to remove
            }
            else
            {
                node* temp = head;
                head = head->next;
                if(head != nullptr)
                {
                    head->prev = nullptr;
                }
                delete temp;
            }
        }
        void removeBack()
        {
            if(head == nullptr)
            {
                return;
            }
            else
            {
                node* temp = tail;
                tail = tail->prev;
                if(tail != nullptr)
                {
                    tail->next = nullptr;
                }
                else
                {
                    head = nullptr;
                }
                delete temp;
            }
        }
        void insertAfter(double target, double x)
        {
            node* current = head;
            while (current != nullptr)
            {
                if (current->data == target)
                {
                    node* newNode = new node(x);
                    newNode->next = current->next;
                    newNode->prev = current;
                    if (current->next != nullptr)
                    {
                        current->next->prev = newNode;
                    }
                    current->next = newNode;
                    if (current == tail)
                    {
                        tail = newNode;
                    }
                    return;
                }
                current = current->next;
            }
        }
        void removeAll(double target)
        {
            node* current = head;
            while (current != nullptr)
            {
                if (current->data == target)
                {
                    node* temp = current;
                    if (current->prev != nullptr)
                    {
                        current->prev->next = current->next;
                    }
                    else
                    {
                        head = current->next;
                    }
                    if (current->next != nullptr)
                    {
                        current->next->prev = current->prev;
                    }
                    else
                    {
                        tail = current->prev;
                    }
                    current = current->next;
                    delete temp;
                }
                else
                {
                    current = current->next;
                }
            }
        }
        void clear()
        {
            node* current = head;
            while (current != nullptr)
            {
                node* temp = current;
                current = current->next;
                delete temp;
            }
            head = nullptr;
            tail = nullptr;
        }
        int countRec()
        {
            return countRecHelper(head);
        }
    private:
        int countRecHelper(node* current)
        {
            if (current == nullptr)
                return 0;
            return 1 + countRecHelper(current->next);
        }
        double sumRec()
        {
            return sumRecHelper(head);
        }
        double sumRecHelper(node* current)
        {
            if (current == nullptr)
                return 0;
            return current->data + sumRecHelper(current->next);
        }
        bool containsRec(double target)
        {
            return containsRecHelper(head, target);
        }
        bool containsRecHelper( double x)
        {

            if (current == nullptr)
                return false;
            if (current->data == target)
                return true;
            return containsRecHelper(current->next, target);
        }
        void printBackwardsRec()
        {
            printBackwardsRecHelper(tail);
        }
        void printBackwardsRecHelper(node* current)
        {
            if (current == nullptr)
                return;
            cout << current->data << " ";
            printBackwardsRecHelper(current->prev);
        }
        double MaxRec()
        {
            return MaxRecHelper(head);
        }
        double MaxRecHelper(node* current)
        {
            if (current == nullptr)
                return -1e308; // or some very small number
            double maxInRest = MaxRecHelper(current->next);
            return (current->data > maxInRest) ? current->data : maxInRest;
        }
        void reverse()
        {
            if (head == nullptr || head->next == nullptr)
            {
                  return;
            }
            else
                {
                     node* current = head;
            node* prev = nullptr;
            node* next = nullptr;
            while (current != nullptr)
            {
                next = current->next;
                current->next = prev;
                current->prev = next;
                prev = current;
                current = next;
            }
            tail = head;
            head = prev;
                }
        }
        void slowSort()
        {
            if (head == nullptr || head->next == nullptr)
                return;
            node* current = head;
            while (current != nullptr)
            {
                node* minNode = current;
                node* runner = current->next;
                while (runner != nullptr)
                {
                    if (runner->data < minNode->data)
                        minNode = runner;
                    runner = runner->next;
                }
                if (minNode != current)
                {
                    double temp = current->data;
                    current->data = minNode->data;
                    minNode->data = temp;
                }
                current = current->next;
            }
        }
};

int main()
{
	doublyLL A;
	A.addBack(5);
	A.addBack(10);
	A.addBack(5);
	A.addBack(15);
	A.addBack(5);
	A.printForwards();   //5, 10, 5, 15, 5,

	cout << "sum: " << A.sum() << endl;              //40
	cout << "max: " << A.getMax() << endl;           //15
	cout << "count of 5: " << A.countOf(5) << endl;  //3
	cout << "item 3: " << A.getAt(3) << endl;        //15

	A.insertAfter(10, 99);
	A.printForwards();   //5, 10, 99, 5, 15, 5,

	A.removeAll(5);
	A.printForwards();   //10, 99, 15,

	cout << "countRec: " << A.countRec() << endl;    //3
	cout << "sumRec: " << A.sumRec() << endl;        //124
	cout << "contains 99: " << A.containsRec(99) << endl;  //1
	A.printBackwardsRec();                           //15 99 10

	//A.reverse();
	//A.printForwards();   //15, 99, 10,

	//A.mergeSort();
	//A.printForwards();   //10, 15, 99,

	return 0;
}