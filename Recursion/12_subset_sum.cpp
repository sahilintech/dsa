// Write a program where a set is given as an array and a sum is given. We have to print the count of subsets whose elements addition is equal to sum.

#include <iostream>
#include <array>
using namespace std;

int subsetCount(int arr[], int n, int sum)
{
    if (n == 0)
        return (sum == 0) ? 1 : 0;
    return subsetCount(arr, n - 1, sum) + subsetCount(arr, n - 1, sum - arr[n - 1]);
}

int main()
{
    int n, sum, i = 0;
    cout << "Enter sum" << endl;
    cin >> sum;
    cout << "Enter size of array " << endl;
    cin >> n;
    int arr[n];
    cout << "Enter elements of array" << endl;
    while (i != n)
    {
        cin >> arr[i];
        i++;
    }
    cout << "No. of subsets whose elements sum is equal to given sum are " << subsetCount(arr, n, sum);
    return 0;
}