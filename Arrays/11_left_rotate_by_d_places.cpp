// Given an array. Rotate it left by given no. of d places

/*
I/p : {10, 0, 12, 13, 1}, d=2
O/p : {12, 13, 1, 10, 0}

Time : O(n)
Space : O(1)

*/

#include <iostream>
using namespace std;

// Reversing array
void reverse(int arr[], int low, int high)
{
    while(low<high)
    {
        swap(arr[low], arr[high]);
        low++;
        high--;
    }
}

void leftRotateByGiven(int arr[], int n, int d)
{
    reverse(arr, 0, d-1); // Reversing 0 to d-1 elements
    reverse(arr, d, n-1); // Reversing d to n-1 elements
    reverse(arr, 0, n-1); // Finally reversing whole array then we will get left rotation
}


int main()
{
    int arr[] = {10, 20, 0, 1, 0, 30, 0, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    int d;
    cout << "Enter no. of places to rotate an array by\n";
    cin >> d; // No. of places
    cout << "Before rotating" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    leftRotateByGiven(arr, n, d);
    cout << "After rotating" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}