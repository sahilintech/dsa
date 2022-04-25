// Given an array of integers, find if it has an equillibrium point
/*
Sum of elements before and after a particular element is equal that element is called equillibrium point

I/p : {3, 4, 8, -9, 20, 6}
O/p : Yes (before and after 20)

I/p : {4, 2, -2}
O/p : Yes {because 2-2 = 0 and before 4 there is no element means zero so 4 is equillibrium point}

Time: O(n)

*/



#include <iostream>
#include <algorithm>
using namespace std;

bool checkEquilliPoint(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }
    int lSum = 0, rSum = 0;
    for (int i = 0; i < n; i++)
    {
        if(lSum == sum-lSum-arr[i])  // If leftSum == rightSum from current element then return true
            return true;
        lSum += arr[i]; // increment leftSum
    }
    return false;
}

int main()
{
    int arr[] = {4, 2, -2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int val = checkEquilliPoint(arr, n);
    if (val)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}