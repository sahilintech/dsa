// Given a fixed array and multiple queries of following types on array, how to effieciently perform these queries
 
/*
I/p : {2, 8, 3, 9, 6, 5, 4}
Queries: getSum(0, 2)
         getSum(1, 3)
         getSum(2, 6)

O/p 13, 20, 27
*/



#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

int prefix_sum[10000];

void preSum(int arr[], int n)
{

    prefix_sum[0] = arr[0];

    for (int i = 1; i < n; i++)
    {
        prefix_sum[i] = prefix_sum[i - 1] + arr[i];
    }
}

int getSum(int prefix_sum[], int l, int r)
{
    if (l != 0)
        return prefix_sum[r] - prefix_sum[l - 1];
    else
        return prefix_sum[r];
}

int main()
{

    int arr[] = {2, 8, 3, 9, 6, 5, 4}, n = 7;

    preSum(arr, n);

    cout << getSum(prefix_sum, 1, 3) << endl;

    cout << getSum(prefix_sum, 0, 2) << endl;
}