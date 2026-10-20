#include <iostream>
#include <stack>
using namespace std;
class Student 
{
private:

    string name;
    int age;
public:
    Student(string n, int a) {
        name = n;
        age = a;
    }

    void print() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
    
};
int main() 
{
    Student* s = new Student("John", 20);
    s->print();
    delete s;
    return 0;
}