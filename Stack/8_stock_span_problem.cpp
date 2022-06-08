/*
Given an array. Return the span of it
Span = Including current day go left side if value is smaller or equal include it in length of current span

I/p : {13, 15, 12, 14, 16, 8, 6, 4, 10, 30}
O/p :  1,  2,  1,  2,  5,  1, 1, 1, 4,  10

I/p : {10, 20, 30, 40}
O/p : 1,  2,  3,  4

I/p: {40, 30, 20, 10}
O/p : 1,  1,  1,  1

// **********  Naive Solution ***********

Time : O(n^2)

#include <iostream>
#include <algorithm>
using namespace std;

void stockSpan(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int len = 1;
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] <= arr[i])
                len++;
            else
                break;
        }
        cout<<len<<" ";
    }
}

int main()
{
    int arr[] = {3, 15, 12, 14, 16, 8, 6, 4, 10, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    stockSpan(arr, n);
    return 0;
}
*/

// Efficient Solution  0(n), Space : O(n)

#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

vector<int> stockSpan(int arr[], int n)
{
    vector<int> v;
    stack<int> s;
    s.push(0); // handle 1st element explicityly
    v.push_back(1);
    for (int i = 1; i < n; i++)
    {
        while (s.empty() == false && arr[s.top()] <= arr[i]) // empty the stack if current index is larget than stack top
            s.pop();
        int span = s.empty() ? i + 1 : i - s.top(); // if stack empty span will be i+1 else current index - previousgreater index
        v.push_back(span);
        s.push(i); // always push index in stack
    }
    return v;
}

int main()
{
    int arr[] = {3, 15, 12, 14, 16, 8, 6, 4, 10, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> v = stockSpan(arr, n);
    for (auto i : v)
        cout << i << " ";
    return 0;
}