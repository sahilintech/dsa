// Find index of largest element present in array

#include <iostream>
using namespace std;
int getLargest(int arr[], int n)
{
    int res = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[res])
        {
            res = i; // if current element in array is greater than previous element update current index in res
        }
    }
    return res;
}

int main()
{
    int arr[] = {5, 8, 20, 100};
    cout << getLargest(arr, 4);
    return 0;
}