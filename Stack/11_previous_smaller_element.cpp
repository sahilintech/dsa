/*
Given an array of distinct integers. Find closest(position-wise) smaller element on left of every element. If there is no smaller on left side print -1

I/p : {15, 10, 18, 12, 4, 6, 2, 8}
O/p :  -1, -1, 10, 10, -1,4,-1, 2

I/p : 8, 10, 12
O/p : -1, 8, 10

Time: 0(n)
Space: O(n)
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

vector<int> prevSmaller(int arr[], int n)
{
    stack<int> s;
    vector<int> v;
    s.push(arr[0]);
    v.push_back(-1);
    for (auto i = 1; i < n; i++)
    {
        while (s.empty() == false && s.top() >= arr[i])
            s.pop();
        int prevSmall = s.empty() ? -1 : s.top();
        v.push_back(prevSmall);
        s.push(arr[i]);
    }
    return v;
}

int main()
{
    int arr[] = {15, 10, 18, 12, 4, 6, 2, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> v = prevSmaller(arr, n);
    for (auto it : v)
        cout << it << " ";
    return 0;
}