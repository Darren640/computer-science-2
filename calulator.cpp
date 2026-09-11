#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;



class Calculator
    {
        private:
            double value;
            vector<double> undoStack;
            vector<double> redoStack;

        void saveState()
        {
            undoStack.push_back(value);
            redoStack.clear(); 
        }
        public: 
        Calculator();
        Calculator(double initialValue)
        {
            value = initialValue;
        }
        void clear()
        {
            saveState();
            value = 0.0;
        }
        void add(double amount)
        {
            saveState();
            value += amount;
        }
        void subtract(double amount)
        {
            saveState();
            value -= amount;

        }
        void multiply(double amount)
        {
            saveState();
            value *= amount;
        }
        void divide(double amount)
        {
            if (amount == 0.0)
            {
                throw invalid_argument("Division by zero is not allowed.");
            }
            saveState();
            value /= amount;
        }
        double display() const
        {
            return value;
        }
        void undo()
        {
            if (!undoStack.empty())
            {
                redoStack.push_back(value);
                value = undoStack.back();
                undoStack.pop_back();
            }
        }
        void redo()
        {
            if (!redoStack.empty())
            {
                undoStack.push_back(value);
                value = redoStack.back();
                redoStack.pop_back();
            }   
        }
        Calculator operator+(const Calculator& other) const
        {
            Calculator result(value);
            result.add(other.display());
            return result;
        }
        
    };




    int main()
    {
        Calculator mycalc;
	
	mycalc.clear();
	mycalc.add(4.52);
	mycalc.add(3.789);
	mycalc.divide(2.6);
	mycalc.multiply(3.12);
	mycalc.subtract(2.678);
	cout << mycalc.display() << endl;       // prints out "7.2928"
	mycalc.clear();
	mycalc.add(5.0);
	cout << mycalc.display() << endl;       // prints out "5"

	// add a constructor
	Calculator calc1;
	cout << calc1.display() << endl;  //prints out 0

	// add a parameterized constructor
	Calculator calc2(5);
	cout << calc2.display() << endl; //prints out 5

	//Optional Challenege #1: Define calculator addition (overload the '+' operator)
	Calculator calc3(7);
	calc1 = calc2 + calc3;
	cout << calc1.display() << endl;  //prints out 12

	//Optional Challenge #2: Create an 'undo' method for the calculator
	mycalc.undo();
	mycalc.undo();
	cout << mycalc.display()<< endl;  //prints out 7.2928

	//Optional Challenge #3: Create a 'redo' method for the calculator
	mycalc.redo();
	mycalc.redo();
	cout << mycalc.display()<< endl;  //prints out 5

    }
