/*
Given an array . Find the length of longest consecutive sequence appearing in any order.

I/p : {1, 9, 3, 4, 2, 20}
O/p : 4 (1, 2, 3, 4 appearing in any order)

I/p : {10, 20, 30}
O/p : 1 (1 element is always consecutive)

Naive Solution = O(nlogn)

#include <iostream>
#include <algorithm>
using namespace std;

int longestConsecutiveSubsequence(int arr[], int n)
{
    sort(arr, arr + n);
    int length = 0;
    int res = 1, curr = 1; // res =1 because we are begining from i=1 in for loop and curr =1 because every array has a subsequence of length 1 i.e current element
    for (int i = 1; i < n; i++)
        if (arr[i] == arr[i - 1]+1)
            curr++;
        else if(arr[i]!=arr[i-1]) // suppose {2, 3, 3, 4} we do not want to count 3 and for next subsequence we will begin from 4
        {
            res = max(res, curr);
            curr = 1;
        }
    return max(res, curr); // because curr can have larger value at last if longest subsequence grows till end then it will not come in 2nd if condition

}

int main()
{
    int arr[] = {0, 9, 3, 4, 2, 6, 8, 7, 9, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<longestConsecutiveSubsequence(arr, n);
    return 0;
}

*/
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

int longestConsecutiveSubsequence(int arr[], int n)
{
    unordered_set<int> s(arr, arr + n);
    int res = 1; // count of present element
    for (auto x : s)
    {
        if (s.find(x - 1) == s.end()) // if for every element x-1 is not present this is the first element of subsequence 
        {
            int curr = 1; // count of present element
            while (s.find(x + curr) != s.end()) // increase current until we donot find that there is no curr+1 
                curr++;
            res = max(res, curr);
        }
    }
    return res;
}

int main()
{
    int arr[] = {1, 3, 4, 3, 3, 2, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << longestConsecutiveSubsequence(arr, n);
    return 0;
}