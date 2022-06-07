/*
Given a string. Return the length of longest substring having distinct chars.

I/p : abac
O/p : 3 (bac)

I/p : aaab
O/p : 2 (ab)
************** Naive Approach *************
// Time: O(n^3)

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

Idea to solve : make a bool vector for every char of a substring make bool arr equal to true to that index if we again found that char return false and compute res, then run for another substring

bool areDistinct(string str, int i, int j)
{
    vector<bool> visited(256);
    for (int k = i; k <= j; k++)
    {
        if (visited[str[k]] == true)
            return false;
        visited[str[k]] = true;
    }
}

int findLongestSubstring(string str)
{
    int n = str.length(), res=0;
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            if (areDistinct(str, i, j))
                res = max(res, j - i + 1);
    return res;
}

int main()
{
    string str = "abac";
    cout<<findLongestSubstring(str);
    return 0;
}


// Time: O(n^2)

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Idea to solve : as soon as we find visited char break and immediately update res and again start new bool array. So we do not have to use an independent O(n) for checking visited chars
int findLongestSubstring(string str)
{
    int n = str.length(), res = 0;
    for (int i = 0; i < n; i++)
    {
        vector<bool> visited(256);
        for (int j = i; j < n; j++)
        {
            if (visited[str[j]] == true)
                break;
            else
            {
                res = max(res, j - i + 1);
                visited[str[j]] = true;
            }
        }
    }
    return res;
}

int main()
{
    string str = "abac";
    cout << findLongestSubstring(str);
    return 0;
}
*/
// Time : O(n)
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int findLongestSubstring(string str)
{
    int n = str.length(), res = 0, maxEnd=0;
    vector<int> prev(256, -1);
    int i=0;
    for(int j=0; j<n; j++)
    {
        i = max(i, prev[str[j]]+1); // if index has already occur i will shift to that prevIndex + 1;
        maxEnd = j-i+1; // then maxEnd will be calculate accordingly.
        res = max(res, maxEnd);
        prev[str[j]] = j; // store index of char in ascii value of char
    }
    return res;
}

int main()
{
    string str = "abac";
    cout << findLongestSubstring(str);
    return 0;
}