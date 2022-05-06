/*
Given an array. Return true if subarray of given array has a sum equal to given sum

I/p : {5, 8, 6, 13}
    sum = 14

O/p : True

*/

#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

bool isSubarray(int arr[], int n, int sum)
{
    unordered_set<int> u;
    int prefixSum = 0;
    for (int i = 0; i < n; i++)
    {
        prefixSum += arr[i];
        if (prefixSum == sum)
            return true;
        if (u.find(prefixSum - sum) != u.end()) // if there is a element in hash set which is equal to prefixSum - sum then return true because previous prefix sum + given sum will form current prefix sum
            return true;
        u.insert(prefixSum);
    }
    return false;
}

int main()
{
    int arr[] = {5, 8, 6, 13};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 13;
    cout << isSubarray(arr, n, sum);
    return 0;
}