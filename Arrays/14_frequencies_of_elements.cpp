// Given a sorted array. Print count of every element how many time it is occuring in array

/*
I/p : {10, 10, 10, 25, 30, 30}
O/p : 3, 1, 2
*/

#include <iostream>
using namespace std;

void printFreq(int arr[], int n)
{
    int freq = 1, i = 1;
    while (i <= n)
    {
        while (i < n && arr[i] == arr[i - 1])
        {
            freq++;
            i++;
        }
        cout << arr[i - 1] << " " << freq << " \n";
        freq = 1;
        i++;
    }
    if (n == 1 || arr[n - 1] != arr[n - 2])
        cout << arr[n - 1] + " " + 1;
}

int main()
{
    int arr[] = {10, 10, 10, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    printFreq(arr, n);
    return 0;
}