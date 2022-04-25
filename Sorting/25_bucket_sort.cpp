/*
Bucket  Sort = Try to place equal elements in each bucket then sort individual buckets and merge them

Ip : {30, 40, 10, 80, 5, 12, 70}
k = 4 (no. of buckets)

O/p : 5, 10, 12, 30, 40, 70, 80

Time: 0(n)
Space: O(1)
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void bucketSort(int arr[], int n, int k)
{
    int max=arr[0];
    for(int i=1; i<n; i++)
        if(arr[i]>max)
        max=arr[i]; 
    max++; // for example if arr is 40 and bucket size is 4 then if we will do k*arr[i] whole divide by max(let 80) then we will get 160/80 which is 2 but it should go in 1 index so  if we do max++; and then divide we will get 1 i.e correct index
    vector<int> bkt[k]; // here array of vecor will have 4 rows 
    for(int i=0; i<n; i++)
    {
        int bi = (k*arr[i])/max; // calculating row of array of vector v  where this element should go
        bkt[bi].push_back(arr[i]); // pushing to that row only
    }
    for(int i=0; i<k; i++)
        sort(bkt[i].begin(), bkt[i].end()); // sorting every row

    int index = 0;
    for(int i=0; i<k; i++)
        for(int j=0; j<bkt[i].size(); j++)
            arr[index++] = bkt[i][j]; // sending each element to array starting from 1st row
}

int main(){
    int arr[] = {30, 40, 10, 80, 5, 12, 70};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 4;
    bucketSort(arr, n, k);
    for(int i=0; i<n; i++)
    cout<<arr[i]<<" ";
    return 0;
}