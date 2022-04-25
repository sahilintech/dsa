// Majority element - An element is called as mojority element if it appears more than n/2 times in an array
// Print either index of majority element else print -1
/*
    I/p : {8, 3, 4, 8, 8}
    O/p : 0 or 3 or 4 (any index)

    I/p : {3, 7, 4, 7, 7, 5}
    O/p : -1
*/

#include <iostream>
#include <algorithm>
using namespace std;

int majorityElement(int arr[], int n)
{

    // Find the candidate
    int res = 0, count = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[res] == arr[i])
            count++;
        else
            count--;
        if (count == 0)
        {
            count = 1;
            res = i;
        }
    }

    // Check if candidate is actually a majority
    count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[res] == arr[i]) // If element at index of majority found appears how many times
            count++;
    }
    if (count <= (n / 2))
        return -1;
    return res;
}

int main()
{
    int arr[] = {20, 30, 40, 50, 50, 50, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int val = majorityElement(arr, n);
    cout << val;
    return 0;
}