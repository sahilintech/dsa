// Union of two sorted arrays
/*
I/p : a[] = {10, 10, 20, 30 ,40}
    b[] = {10, 50, 60}

O/p : {10, 20, 30, 40, 50, 60}

Time: O(m+n)
Space: O(1)
*/

#include <iostream>
#include <algorithm>
using namespace std;

void unionOfArrays(int arr1[], int arr2[], int n1, int n2)
{
    int i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        if (i > 0 && arr1[i] == arr1[i - 1]) // If two elements are same in array continue loop
        {
            i++;
            continue;
        }
        if (j > 0 && arr2[j] == arr2[j - 1]) // If two elements are same in array continue loop
        {
            j++;
            continue;
        }
        if (arr1[i] < arr2[j])
        {
            cout << arr1[i] << " ";
            i++;
        }
        else if (arr2[j] < arr1[i])
        {
            cout << arr2[j] << " ";
            j++;
        }
        else
        {
            cout << arr1[i] << " ";
            i++;
            j++;
        }
    }
    while (i < n1)
    {
        if (i > 0 && arr1[i] != arr1[i - 1])  // Remaining elements printed and checking duplicacy
        {
            cout << arr1[i] << " ";
            i++;
        }
    }
    while (j < n2)
    {
        if (j > 0 && arr2[j] != arr2[j - 1])
        {
            cout << arr2[j] << " ";
            j++;
        }
    }
}

int main()
{
    int arr1[] = {3, 5, 10, 10, 10, 15, 15, 20};
    int arr2[] = {5, 10, 10, 10, 15, 15, 15, 30, 30};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    unionOfArrays(arr1, arr2, n1, n2);
    return 0;
}