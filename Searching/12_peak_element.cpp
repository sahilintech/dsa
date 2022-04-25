// Given an array. Find peak element in the array
// Peak element is the one which is greater than its neighbours

/*
I/p : {5, 10, 20, 15, 7}
O/p : 20 (20 is greater than 10 and 15 which are neighbours of 20)

I/p : {80, 70, 90}
O/p : 80 or 90 (Both are greater than 70 which is a single neighbour of both return 80 or 90)

Time = O(log n)
*/

#include<iostream>
#include<algorithm>
using namespace std;

int peakEle(int arr[], int n)
{
    int low = 0, high = n-1;
    while(low<=high)
    {
        int mid = (low+high)/2;
        if((arr[mid]==0 || arr[mid-1] <= arr[mid]) && (arr[mid]==n-1 || arr[mid+1] <= arr[mid]))
            return mid;
        if(mid > 0 && arr[mid-1]>=arr[mid])
            high = mid-1;
        else
            low = mid-1;
    }
    return -1;
}

int main(){
    int arr[] = {5, 10, 20, 15, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int val = peakEle(arr, n);
    cout<<val;
    return 0;
}