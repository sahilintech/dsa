// Given a binary array flip all 0's or 1's  such that binary array have all same elements and no. of flips requred are minimum
// You can flip either 0's or 1's and flips should be consecutive and minimum.

/*
I/p : {1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1}
O/p : Flip from 1 to 3
      Flip from 5 to 6 
Here above two flips are required and flipping zeroes because they requires min. flips

I/p : {1, 1, 1}
O/p : Don't print anything as elements are already same

I/p : {0, 1}
O/p : Print one of both below
      Flip from 0 to 0
      Flip from 1 to 1
*/

#include <iostream>
#include <algorithm>
using namespace std;

void printFlips(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        if (arr[i] != arr[i-1])
        {
            if (arr[i] != arr[0]) // Indicates a new group is started else new group ended at previous i
                cout << "Flip from " << i << " to ";
            else
                cout << n - 1 << endl;
        }
    }
    if (arr[0] != arr[n - 1])
        cout << n - 1 << endl; // Handling cases like {1, 0, 0, 1, 0} at last element a new group is started and for loop will not execute else part
}

int main()
{
    int arr[] = {1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    printFlips(arr, n);
    return 0;
}