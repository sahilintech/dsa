/*
Given an array of distinct integers. Find closest(position-wise) greater on left of every element. If there is no greater on left side print -1

I/p : {15, 10, 18, 12, 4, 6, 2, 8}
O/p :  -1, 15, -1, 18, 12,12,6, 12

I/p : 8, 10, 12
O/p : -1, -1, -1

Time: 0(n)
Space: O(1)
*/

#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

void prevGreater(int arr[], int n)
{
    stack<int> s;
    s.push(arr[0]);
    cout << "-1"
         << " ";
    // push every item to stack and remove items until we do not find s.top > arr[i]
    for (int i = 1; i < n; i++)
    {
        while (s.empty() == false && s.top() <= arr[i])
            s.pop();
        int prevGreat = s.empty() ? -1 : s.top();
        cout << prevGreat << " ";
        s.push(arr[i]);
    }
}

int main()
{
    int arr[] = {15, 10, 18, 12, 4, 6, 2, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    prevGreater(arr, n);
    return 0;
}