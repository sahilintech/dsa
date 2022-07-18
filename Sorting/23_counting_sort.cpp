/*
Given an array and value of k . Array contains elements in the range of k. Sort the array

I/p : {1, 4, 4, 1, 0, 1}
    k = 5 (k is range ie elements are present from 0 to 5)

O/p : {0, 1, 1, 1, 4, 4}

Time: O(n+k);
Space: O(n+k);
*/

#include <iostream>
#include <algorithm>
using namespace std;
const int k = 5;
void countingSort(int arr[], int n)
{
    int temp[k] = {0};

    for (int i = 0; i < n; i++)
        temp[arr[i]]++;

    for (int i = 1; i < k; i++)
        temp[i] = temp[i - 1] + temp[i];

    int *output = new int[n];
    for (int i = n - 1; i >= 0; i--)
    {
        output[temp[arr[i]] - 1] = arr[i];
        temp[arr[i]]--;
    }
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

int main()
{
    int arr[] = {1, 4, 4, 1, 0, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    countingSort(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}