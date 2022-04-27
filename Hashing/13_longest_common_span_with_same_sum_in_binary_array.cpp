/*
Given two arrays . Find the subarray from both arrays whose sum is equal and return the length of longest subarray

I/p : arr1[] = {0, 1, 0, 0, 0, 0}
      arr2[] = {1, 0, 1, 0, 0, 1}

O/p : 4

Time : 0(n)
Space: 0(n)
*/

#include <iostream>
#include <algorithm>
#include "0_header.h"
using namespace std;

int longestSpan(int arr1[], int arr2[], int n)
{
    int *temp = new int[n];
    for (int i = 0; i < n; i++) // store the subtraction of both arrays in temp and pass it to the longest length of subarray with given sum function
        temp[i] = arr1[i] - arr2[i];
    longestLength(temp, n, 0);
}

int main()
{
    int arr1[] = {0, 1, 0, 0, 0, 0};
    int arr2[] = {1, 0, 1, 0, 0, 1};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    cout << longestSpan(arr1, arr2, n);
    return 0;
}