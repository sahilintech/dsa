// You are given an binary array. Print the maximum consecutive's one in an array.
/*
I/p : {0, 1, 1, 0, 1, 0}
O/p : 2

I/p : {1, 1, 1, 1}
O/p : 4

Time = O(n)
*/

#include <iostream>
#include <algorithm>
using namespace std;

int maxConsec1(bool arr[], int n)
{
    int count = 0, res = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            count++;
            res = max(res, count); // Store max value of count in max
        }
        else
            count = 0; // if arr[i] is 0 then count again.
    }
    return res;
}

int main()
{
    bool arr[] = {1, 0, 1, 1, 0, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int val = maxConsec1(arr, n);
    cout << val;
    return 0;
}