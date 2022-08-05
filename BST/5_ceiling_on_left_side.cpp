/*
Given an array. Find the ceiling for every element i.e its next greater element or equal ele present on left side if not present print -1.

Time: O(nlogn) log n for lower_bound
Space: O(1)
*/
#include <iostream>
#include <algorithm>
#include <limits.h>
#include <set>
using namespace std;

void printCeilForEveryEle(int arr[], int n)
{
    set<int> s;
    s.insert(arr[0]);
    cout << -1 << " ";
    for (int i = 1; i < n; i++)
    {
        auto it = s.lower_bound(arr[i]); // lower bound returns iterator to element if it is present else it returns iterator to its next greater element.
        if (it != s.end())
            cout << *it << " ";
        else
            cout << -1 << " ";
        s.insert(arr[i]);
    }
}

int main()
{
    int arr[] = {2, 30, 30, 15, 25, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    printCeilForEveryEle(arr, n);
    return 0;
}