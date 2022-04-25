/*
Given an array. Count how many intersection array elements are forming. Avoid duplicate array formations
I/p : a[]= {10, 15, 20, 5, 30}
      b[]= {30, 5, 30, 80}

O/p : 2

I/p : a[]= {10, 10, 10}
      b[]= {10, 10, 10}

Naive: O(n1*(n1+n2))

#include <iostream>
#include <algorithm>
using namespace std;

int countIntersections(int arr1[], int arr2[], int n1, int n2)
{
    int res = 0;
    for (int i = 0; i < n1; i++)
    {
        bool flag = false;
        for (int j = 0; j < i; j++)
        {
            if (arr1[i] == arr1[j])
            {
                flag = true;
            }
        }
        if (flag == true)
            continue;
        for (int j = 0; j < n2; j++)
        {
            if (arr1[i] == arr2[j])
            {
                res++;
                break;
            }
        }
    }
    return res;
}

int main()
{
    int arr1[] = {10, 15, 20, 5, 80};
    int arr2[] = {30, 5, 30, 80};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    cout<<countIntersections(arr1, arr2, n1, n2);
    return 0;
}
*/

//

#include <iostream>
#include <unordered_set>
#include <algorithm>
using namespace std;

int countIntersections(int arr1[], int arr2[], int n1, int n2)
{
    unordered_set <int> u1(arr1, arr1+n1);
    unordered_set <int> u2(arr2, arr2+n2);
    

}

int main()
{
    int arr1[] = {10, 15, 20, 5, 80};
    int arr2[] = {30, 5, 30, 80};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << countIntersections(arr1, arr2, n1, n2);
    return 0;
}