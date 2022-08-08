/*
Given a sum. and an array of price of items .Purchase max no. of items such that sum of prices of all items should not be larger than given sum

Time: O(n) + O(count*logn)
*/

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int purchaseMaximumItems(int arr[], int n, int sum)
{
    priority_queue<int, vector<int>, greater<int>> pq(arr, arr + n);
    int givenSum = 0, count = 0;
    for (int i = 0; i < n; i++)
    {
        if (pq.top() < sum && givenSum + pq.top() <= sum)
        {
            givenSum += pq.top();
            pq.pop();
            count++;
        }
        else
            break;
    }
    return count;
}

int main()
{
    int arr[] = {1, 12, 5, 111, 200};
    int n = 5;
    int sum = 10;
    cout << purchaseMaximumItems(arr, n, sum);
    return 0;
}