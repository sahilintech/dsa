// Given an array of infinite size. Return the index of element x in that array, if element is not present return -1
// Time = O(log(pos))

#include <iostream>
#include <algorithm>
using namespace std;

int binarySearch(int arr[], int x, int low, int high)
{
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == x)
            return mid;
        else if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int searchEle(int arr[], int x)
{
    if (arr[0] == x) // Implicitly checking first element
        return 0;
    int i = 1;
    while (arr[i] < x) // Finding high index
        i *= 2;
    if (arr[i] == x) // Checking is high index element is equal or not
        return i;
    return binarySearch(arr, x, (i / 2) + 1, i - 1);  // Doing binary search from low to high, low is i/2 + 1 because i/2 is computed in while loop and it was smaller than x so no need to find previous elements
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int x;
    cin >> x;
    int val = searchEle(arr, x);
    cout << "At index " << val;
    return 0;
}