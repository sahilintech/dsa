/*
Given an array and a value k . Find the no. of distinct elements in every window of size k

I/p : {10, 10, 5, 3, 20, 5}
k = 4

O/p : 3, 4, 3

Explanation:
Total no. of windows = n-k+1
1st window of size k = 10, 10, 5, 3 = Distinct ele = 3
2nd window of size k = 10, 5, 3, 20 = Distinct ele = 4
3rd window of size k = 5, 3, 20, 5 = Distinct ele = 3

************* Naive Solution *************
Time: O(n-k)*k*k

#include <iostream>
#include <algorithm>
using namespace std;

void countDistinctElements(int arr[], int n, int k)
{
    for (int i = 0; i <= n - k; i++)
    {
        int count = 0;
        for (int j = 0; j < k; j++)
        {
            bool flag = false;
            for (int p = 0; p < j; p++)
            {
                if (arr[i + j] == arr[i + p])
                {
                    flag = true;
                    break;
                }
            }
            if (flag == false)
                count++;
        }
        cout << count << endl;
    }
}

int main()
{
    int arr[] = {10, 10, 5, 3, 20, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;
    countDistinctElements(arr, n, k);
    return 0;
}

*/
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

void countDistinctElements(int arr[], int n, int k)
{
    unordered_map<int, int> m;
    for (int i = 0; i < k; i++)
        m[arr[i]]++;
    cout << m.size() << " "; // count of distinct elements of first window
    for (int i = k; i < n; i++)
    {
        auto it = m.find(arr[i - k]);
        m[arr[i - k]]--; // reduce count value starting from 1st element one by one
        if (it->second == 0)
            m.erase(arr[i - k]); // erase the previous element before the first element of current subsequence if its count becomes zero
        m[arr[i]]++; // insert new element or increasing count of existing element
        cout << m.size() << " ";
    }
}

int main()
{
    int arr[] = {10, 10, 5, 3, 20, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;
    countDistinctElements(arr, n, k);
    return 0;
}