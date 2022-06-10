/*
Given a array representing heights of histogram. Find the largest rectangular area it can cover

I/p : {6, 2, 5, 4, 1, 5, 6}
O/p : 10(5*2) (bars of height 5 and 6 will contribute to max area as width is 2 and from both bars min height is 5 so 5*2)

*/

//******* Naive Solution************* => Time : O(n^2)

#include <iostream>
#include <algorithm>
using namespace std;

int largestRectArea(int arr[], int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = arr[i];
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] >= arr[i])
                sum += arr[i];
            else
                break;
        }
        for (int k = i + 1; k < n; k++)
        {
            if (arr[k] >= arr[i])
                sum += arr[i];
            else
                break;
        }
        res = max(res, sum);
    }
    return res;
}

int main()
{
    int arr[] = {6, 2, 5, 4, 1, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << largestRectArea(arr, n);
    return 0;
}