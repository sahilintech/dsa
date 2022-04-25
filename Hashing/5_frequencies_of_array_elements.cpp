/*
Given an array. Print frequency of every elements in array in any order

I/p : {10, 12, 10, 15, 10, 20, 12, 12}
O/p : 10 3
      12 3
      15 1
      20 1

********NAIVE SOLUTION************
#include <iostream>
#include <algorithm>
using namespace std;

void frequencyOfElements(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        bool flag = false;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] == arr[j])
            {
                flag = true;
                break;
            }
        }
        if (flag == true)
            continue;
        int frequency = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
                frequency++;
        }
        cout << arr[i] << " " << frequency << "\n";
    }
}

int main()
{
    int arr[] = {10, 12, 10, 15, 10, 20, 12, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    frequencyOfElements(arr, n);
    return 0;
}

*/

// Time: 0(n), Space: O(n)
#include<iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;

void frequencyOfElements(int arr[], int n)
{
    unordered_map <int, int> m;
    for(int i=0; i<n; i++)
    m[arr[i]]++; // m[10 , 1] will be done first and if again 10 occurs in array it will do m[10]++ means 10, 2 will be done it simply increments the value of key
    for(auto i: m)
    cout<<i.first<<" "<<i.second<<endl;
}

int main(){
    int arr[] = {10, 12, 10, 15, 10, 20, 12, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    frequencyOfElements(arr, n);
    return 0;
    return 0;
}