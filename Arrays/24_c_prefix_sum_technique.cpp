// Given n ranges, find the maximum appearing element in these ranges.
/*
I/p :  Starting_point[] = {1, 2, 5, 15}
       Ending point[] = {5, 8, 7, 18}

O/p : 5

Ranges above are [1, 5] = (1, 2, 3, 4, 5✔️)
                 [2, 8] = (2, 3, 4, 5✔️, 6, 7, 8)
                 [5, 7] = (5✔️, 6, 7)
                 [15, 18] = (15, 16, 17, 18)
            
*/

#include <bits/stdc++.h>
using namespace std;

int getMaxElementInRanges(int l[], int r[], int n)
{
    int arr[1000];
    memset(arr, 0, sizeof(arr));
    for(int i=0; i<n; i++)
    {
        arr[l[i]]++; 
        arr[r[i]+1]--; 
    }
    int res, maxAppearing = 0;
    for(int i=0; i<1000; i++)
    {
        arr[i] = arr[i-1] + arr[i];  // Prefix sum
        if(maxAppearing<arr[i])
        {
            maxAppearing = arr[i];
            res = i;
        }
    }
    return res;
}

int main(){
    int startingOfRange[] = {1, 9, 5, 16};
    int endingOfRange[] = {5, 15, 7, 18};
    int n = sizeof(startingOfRange)/sizeof(startingOfRange[0]);
    int val = getMaxElementInRanges(startingOfRange, endingOfRange, n);
    cout<<val;
    return 0;
}