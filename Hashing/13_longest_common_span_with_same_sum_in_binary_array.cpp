/*
Given two arrays . Find the subarray from both arrays whose sum is equal and return the length of longest subarray

I/p : arr1[] = {0, 1, 0, 0, 0, 0}
      arr2[] = {1, 0, 1, 0, 0, 1}

O/p : 4
*/

#include <iostream>
#include <algorithm>
using namespace std;

int longestSpan(int arr1[], int arr2[], int n)
{
    int length = 0;
    for (int i = 0; i < n; i++)
    {
        int arr1CurrSum = 0, arr2CurrSum = 0;
        for (int j = i; j < n; j++)
        {
            arr1CurrSum += arr1[j];
            arr2CurrSum += arr2[j];
            if (arr1CurrSum == arr2CurrSum)
                length = max(length, j - i + 1);
        }
    }
    return length;
}

int main()
{
    int arr1[] = {0, 1, 0, 0, 0, 0};
    int arr2[] = {1, 0, 1, 0, 0, 1};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    cout << longestSpan(arr1, arr2, n);
    return 0;
}