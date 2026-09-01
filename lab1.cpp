#include <iostream>
#include <string>
#include <fstream>
using namespace std;


    //template the class
    template<typename string>
    string binarySearch()
    

    int binarySearch(double* A, int start, int end, double key) 
    {
    while(start <= end)
    {
        int mid = (start + end) / 2;
        
        if(key == A[mid])
        {
            return mid;
        }
        else if(key < A[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }   
        
    }
    return -1;
    }


int main()
{
    
	double* A;
	A = new double[10];

	A[0] = -5.2;
	A[1] = -2.3;
	A[2] = 1.7;
	A[3] = 4.2;
	A[4] = 7;
	A[5] = 12;
	A[6] = 27;
	A[7] = 32;
	A[8] = 42;
	A[9] = 67;
	
	
		//Step 1: Implement Binary Search
	cout << binarySearch(A, 0, 9, 32.0) << endl; //7
	cout << binarySearch(A, 0, 9, -2.3) << endl; //1
	cout << binarySearch(A, 0, 9, 67.0) << endl; //9
	cout << binarySearch(A, 0, 9, 10.2) << endl; //-1 (not found)
	
	
	//Step 2: Template your binary search	string* B;
	B = new string[6];
	B[0] = "apple";
	B[1] = "banana";
	B[2] = "date";
	B[3] = "orange";
	B[4] = "orchid";
	B[5] = "pear";

    string key = "orange";
	cout << binarySearch(B, 0, 5, key) << endl; //3

return 0;
}