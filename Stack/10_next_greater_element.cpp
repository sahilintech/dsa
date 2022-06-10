/*
Given an array. Find the next greater (position wise closest) element on right side for every array element

I/p : arr[] = {5, 15, 10, 8, 6, 12, 9, 18}
O/p :          15,18, 18, 12,12,18, 18, -1

Time: 0(n), Space: O(n)
*/

#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextGreater(int arr[], int n)
{
    stack<int> s;
    vector<int> v;
    s.push(arr[n - 1]);
    v.push_back(-1);
    for (int i = n - 2; i >= 0; i--)
    {
        while (s.empty() == false && s.top() <= arr[i])
            s.pop();
        int nextGreat = s.empty() ? -1 : s.top();
        v.push_back(nextGreat);
        s.push(arr[i]);
    }
    reverse(v.begin(), v.end());
    return v;
}

int main()
{
    int arr[] = {5, 15, 10, 8, 6, 12, 9, 18};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> v = nextGreater(arr, n);
    for (auto i : v)
        cout << i << " ";
    return 0;
}