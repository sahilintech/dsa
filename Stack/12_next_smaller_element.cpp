/*
Given an array of distinct integers. Find closest(position-wise) greater on left of every element. If there is no greater on left side print -1

I/p : {15, 10, 18, 12, 4, 6, 2, 8}
O/p :  10, 4, 12, 4,   2, 2, -1,-1

I/p : 8, 10, 12
O/p : -1, -1, -1

Time: 0(n)
Space: O(n)
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextSmaller(int arr[], int n)
{
    stack<int> s;
    vector<int> v;
    s.push(arr[0]);
    v.push_back(-1);
    for (auto i = n - 2; i >= 0; i--)
    {
        while (s.empty() == false && s.top() >= arr[i])
            s.pop();
        int nextSmall = s.empty() ? -1 : s.top();
        v.push_back(nextSmall);
        s.push(arr[i]);
    }
    reverse(v.begin(), v.end());
    return v;
}

int main()
{
    int arr[] = {15, 10, 18, 12, 4, 6, 2, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> v = nextSmaller(arr, n);
    for (auto it : v)
        cout << it << " ";
    return 0;
}