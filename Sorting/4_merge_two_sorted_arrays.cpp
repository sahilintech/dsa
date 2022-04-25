/*
Given two sorted arrays merge them and print elements in sorted order

I/p : a[] = {10, 15, 20}
     b[] = {5, 6, 6, 15}

O/p : 5, 6, 6, 10, 15, 15, 20

Time: 0(m+n)
Space: O(1);
*/

#include <iostream>
#include <algorithm>
using namespace std;

void mergeArrays(int arr1[], int arr2[], int m, int n)
{
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (arr1[i] <= arr2[j])
        {
            cout << arr1[i] << " ";
            i++;
        }
        else
        {
            cout << arr2[j] << " ";
            j++;
        }
    }
    while (i < m)
        cout << arr1[i++] << " ";
    while (j < n)
        cout << arr2[j++] << " ";
}

int main()
{
    int arr1[] = {10, 15, 20, 20};
    int arr2[] = {10, 12};
    int a = sizeof(arr1) / sizeof(arr1[0]);
    int b = sizeof(arr2) / sizeof(arr2[0]);
    mergeArrays(arr1, arr2, a, b);
    return 0;
}
