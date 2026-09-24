//////////////////////////////////////////////////////
// Topics: circular arrays, templated classes, dynamic arrays
//
// Implement a stackQueue using a
// circular array implementation as discussed in class.
// Your data structure must increase its array size dynamically
// if the array runs out of room.
//
// Abstractly, your stackQueue represents a list of items
// with a front and back from which items may be added
// or removed.  If you choose to add and remove from just
// one end, you effectively have a stack.  If you choose
// to add to the back and remove from the front, (or vice versa)
// you effectively have a queue, thus the name "stackQueue".
//
//
///////////////////////////////////////////////////////
#include <iostream>
using namespace std;




template <class T>
class stackQueue
{
private:
    //declare your array variable and
    //any additional variables you need
    //to solve the problem
    T* array;
    int arraySize;
    int front;
    int back;
    int count;

public:
    stackQueue()
    {
        this->arraySize = 15;
        array = new T[arraySize];
        front = 0;
        back = 0;
        count = 0;
    }

    //Insert x to the "back" of the list of items.
    void addBack(T x)
    {
        if (count == arraySize) 
        {
            T* newArray = new T[arraySize * 2];
            for (int i = 0; i < count; i++) {
                newArray[i] = array[(front + i) % arraySize];
            }
            delete[] array;
            array = newArray;
            arraySize *= 2;
            front = 0;
            back = count;
        }
        array[back] = x;
        back = (back + 1) % arraySize;
        count++;
    }

    //Add x to the "front" of the list of items.
    void addFront(T x)
    {
        if (count == arraySize) 
        {
            T* newArray = new T[arraySize * 2];
            for (int i = 0; i < count; i++) {
                newArray[i] = array[(front + i) % arraySize];
            }
            delete[] array;
            array = newArray;
            arraySize *= 2;
            front = 0;
            back = count;
        }
        front = (front - 1 + arraySize) % arraySize;
        array[front] = x;
        count++;
    }

    //Remove and return the item currently at the "back" of the list
    T removeBack()
    {
        back = (back - 1 + arraySize) % arraySize;
        T value = array[back];
        count--;
        return value;
    }

    //Remove and return the item currently at the "front" of the list
    T removeFront()
    {
        T value = array[front];
        front = (front + 1) % arraySize;
        count--;
        return value;
    }

    //Is the stackQueue empty?
    bool empty()
    {
        return count == 0;
    }
};



int main()
{
	stackQueue<int> Q1;

	Q1.addBack(10);
	Q1.addBack(11);
	Q1.addBack(12);
	Q1.addBack(13);
	Q1.addBack(14);
	Q1.addBack(15);
	Q1.addBack(16);
	Q1.addFront(9);
	Q1.addFront(8);

	cout << Q1.removeFront() << endl;  //8
	cout << Q1.removeFront() << endl;  //9
	cout << Q1.removeFront() << endl;  //10

	cout << Q1.removeBack() << endl;   //16
	cout << Q1.removeBack() << endl;   //15
	cout << Q1.removeBack() << endl;   //14

	return 0;
}