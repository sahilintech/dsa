// Given a sorted array and sum, find if there is a triplet with given sum
/*
I/p : {2, 3, 4, 8, 9, 20, 40}
    x = 32
O/p : Yes (4+8+20)

Time : O(n^2)
*/

#include <iostream>
#include <algorithm>
using namespace std;

bool twoPointer(int arr[], int left, int right, int x)
{
    while (left < right) // left is not equal to right because pairs cannot be same
    {
        int cal = arr[left] + arr[right];
        if (cal == x)
            return true;
        else if (cal < x) // If sum is smaller move left pointer forward as array is sorted and it will give us greater sum
            left++;
        else
            right--;
    }
    return false;
}

bool tripletSum(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (twoPointer(arr, i + 1, n - 1, x - arr[i]))
            return true;
    }
    return false;
}

int main()
{
    int arr[] = {2, 3, 4, 8, 9, 20, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 21;
    cout << tripletSum(arr, n, x);
    return 0;
}