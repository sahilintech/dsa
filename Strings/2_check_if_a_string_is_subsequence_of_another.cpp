/*
Given two strings. Check if 2nd string is a subsequence of first

Note: (Subsequences of ABC are "", "A", "B", "C", "AB", "BC", "AC", "ABC")

I/p : "ABCD"
O/p : "AD"

Time: O(n)
Space: O(1)

************* Iterative Solution ***************
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool checkSubsequence(string &str1, string &str2)
{
    if (str1.length() < str2.length())
        return false;
    int i = 0, j = 0;
    while (i < str1.length() && j < str2.length())
    {
        if (str1[i] == str2[j])
        {
            i++;
            j++;
        }
        else
            i++;
    }
    return (j == str2.length());
}
int main()
{
    string str1 = "abcd";
    string str2 = "abd";
    if (checkSubsequence(str1, str2))
        cout << "Yes";
    else
        cout << "No";
    return 0;
}

*/

// ************* Recursive Solution ***************

#include <iostream>
#include <algorithm>
using namespace std;

bool checkSubsequence(string str1, string str2, int n, int m)
{
    if (m == 0)
        return true;
    if (n == 0)
        return false;
    if (str1[n - 1] == str2[m - 1])
        return checkSubsequence(str1, str2, n - 1, m - 1);
    else
        return checkSubsequence(str1, str2, n - 1, m);
}

int main()
{
    string str1 = "abcd";
    string str2 = "aba";
    int n = str1.length();
    int m = str2.length();
    if (checkSubsequence(str1, str2, n, m))
        cout << "Yes";
    else
        cout << "No";
    return 0;
}

// Note = Iterative solution is better than recursive because we need extra space in recursive solution with same time complexity