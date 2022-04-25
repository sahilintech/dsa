// Given an array. Rotate it left by one positon.

/* 
Input: {10, 0, 23, 5, 6}
Output: {0, 23, 5, 6, 10}
*/

#include <iostream>
using namespace std;

void leftRotateByOne(int arr[], int n)
{
    int temp = arr[0];
    for (int i = 1; i < n; i++)
        arr[i - 1] = arr[i];
    arr[n - 1] = temp;
}

int main()
{
    int arr[] = {10, 20, 0, 1, 0, 30, 0, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Before rotating" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    leftRotateByOne(arr, n);
    cout << "After rotating" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}