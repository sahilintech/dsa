// Given an array containing zeroes and other elements. Move the zeroes to the end without alternating the position of other elements.
/* 
I/p : {10, 0, 0, 23, 0, 2}
O/p : {10, 23, 2, 0, 0, 0}

I/p : {10, 20}
O/p : {10, 20}
*/

#include <iostream>
using namespace std;

void moveToEnd(int arr[], int n)
{
    int count = 0; // Count of non zero elements
    for (int i = 0; i < n; i++)
        if(arr[i]!=0)
        {
            swap(arr[count], arr[i]);
            count++;
        }
}

int main()
{
    int arr[] = {10, 20, 0, 1, 0, 30, 0, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Before moving zeroes" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    moveToEnd(arr, n);
    cout << "After moving zeroes" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}