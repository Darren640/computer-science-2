#include <iostream>
using namespace std;

/*int binarysearch(int A[], int start, int end, int key)
{
    while (start <= end)
    {
        int mid = (start + end) / 2;

            if (A[mid] == key)
            {
                return mid;
            }
            else if (A[mid] < key)
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
*/
    int findsmallest(int* A, int start, int end)
    {
        int small = start;
        for(int i = start + 1; i <= end; i++)
        {
            if(A[i] < A[small])
            {
                small = i;
            }
        }
        return small;
    }

    void selectionsort(int* A, int start, int end)
    {
        for(int i = start; i <= end; i++)
        {
            int small = findsmallest(A, i, end);

            swap(A[i], A[small]);
        }
    }  

    int main()
    {
        /*int A[10] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50};
        int target;
        cout << "Enter the target value: ";
        cin >> target;
        int result = binarysearch(A, 0, 9, target);
        if(result != -1)
            cout << "Found at index: " << result << endl;
        else
            cout << "Not found" << endl;
        */

        int A*;
        A = new int[5];


    }