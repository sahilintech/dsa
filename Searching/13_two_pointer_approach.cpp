// Given a sorted array and a sum, find if there is a pair with given sum
/*
I/p : {2, 5, 8, 12, 30}
    X = 17
O/p : Yes (5+12 = 17)

I/p : {3, 8, 13, 18}
    X = 14
O/p : No
*/

#include <iostream>
#include <algorithm>
using namespace std;

bool twoPointer(int arr[], int x, int n)
{
    int left = 0, right = n - 1;
    while (left < right) // left is not equal to right because pairs cannot be same
    {
        int cal = arr[left] + arr[right];
        if (cal == x)
            return true;
        else if (cal < x) // If sum is smaller move left pointer forward as array is sorted and it will give us greater sum
            left++;
        else
            right--;
    }
    return false;
}

int main()
{
    int arr[] = {2, 5, 8, 12, 30};
    int x = 7;
    cout << twoPointer(arr, x, 5);
    return 0;
}