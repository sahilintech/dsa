// Check if an array is sorted or not

#include <iostream>
using namespace std;

bool isSorted(int arr[], int n)
{
    for (int i = 1; i < n; i++)
        if (arr[i] < arr[i - 1])
            return false;
    return true;
}

int main()
{
    int arr[] = {10, 20, 30, 400};
    cout << isSorted(arr, 4);
    return 0;
}