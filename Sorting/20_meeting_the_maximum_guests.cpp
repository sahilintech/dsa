// Time : O(nlogn)

#include<iostream>
#include<algorithm>
using namespace std;

int maxGuests(int arr[], int dep[], int n)
{
    sort(arr, arr+n);
    sort(dep, dep+n);
    int i=0, j=0, count=0, res=0;
    while(i<n && j<n)
    {
        if(arr[i]<=dep[j])
        {
            count++;
            i++;
        }
        else
        {
            count--;
            j++;
        }
        res = max(res, count);
    }
    return res;
}

int main(){
    int arr[] = {900, 600, 700}; //Arrival time
    int dep[] = {1000, 800, 730}; //Departure time
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<maxGuests(arr, dep, n);
    return 0;
}