/*
Given an array and a value k. Print the elements which are appearing more than n/k times

I/p : {30, 10, 20, 20, 10, 20, 30, 30}
k = 4

O/p : 20, 30 (n/k = 2 and 20, 30 appears more than 2 times)

************ Naive Solution *************
Time: 0(nlogn)
#include<iostream>
#include<algorithm>
using namespace std;

void moreThanNByKOccurences(int arr[], int n, int k)
{
    sort(arr, arr+n);
    int i=1, count =1;
    while(i<n)
    {

        while(i<n && arr[i]==arr[i-1])
        {
            i++;
            count++;
        }
        if(count>(n/k))
        cout<<arr[i-1]<<" ";
        count = 1;
        i++;
    }
}

int main(){
    int arr[] = {30, 10, 20, 20, 10, 20, 30, 30};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 4;
    moreThanNByKOccurences(arr, n, k);
    return 0;
}

********* Efficient solution if k is very very large************
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

void moreThanNByKOccurences(int arr[], int n, int k)
{
    unordered_map <int, int> m;
    for(int i=0; i<n; i++)
    m[arr[i]]++;
    for(auto it: m)
    if(it.second > (n/k))
    cout<<it.first<<" ";
}


int main()
{
    int arr[] = {30, 10, 20, 20, 10, 20, 30, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;
    moreThanNByKOccurences(arr, n, k);
    return 0;
}
*/

// Efficient solution if k is very very small and n is very very large  
// Time: 0(nk) , Space = 0(k-1)
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

void moreThanNByKOccurences(int arr[], int n, int k)
{
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        if (m.find(arr[i]) != m.end())
            m[arr[i]]++;
        else if (m.size() < k - 1)
            m.insert({arr[i], 1});
        else
        {
            m[arr[i]]--;
            if (arr[i] == 0)
                m.erase(arr[i]);
        }
    }
    for (auto x : m)
    {
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (x.first == arr[i])
                count++;
        }
        if (count > (n / k))
            cout << x.first << " ";
    }
}

int main()
{
    int arr[] = {30, 10, 20, 20, 10, 20, 30, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;
    moreThanNByKOccurences(arr, n, k);
    return 0;
}