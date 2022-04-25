// Find index of second largest element present in array
/*
I/p : {10, 10, 10}
O/p : -1

I/p : {10, 2, 30, 40}
O/p : 2(index of 30)
*/

#include <iostream>
using namespace std;

int getsecondLargest(int arr[], int n)
{
    int res = -1, largest = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[largest]) // if current element is greater than previous element
        {
            res = largest; // update largest
            largest = i;   // previous largest will become second largest
        }
        else if (arr[i] != arr[largest])
        {
            if (res == -1 || arr[i] > arr[res])
            {
                res = i;
            }
        }
    }
    return res;
}

int main()
{
    int arr[] = {10, 10, 10, 10, 10, 10};
    cout << getsecondLargest(arr, 6);
    return 0;
}