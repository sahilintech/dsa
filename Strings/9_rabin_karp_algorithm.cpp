/*
Given two strings a text string and a pattern string. We need to return the indices of text string on which pattern string appears

I/p : abdabcbabc
    abc

O/p : 3, 7

Time : O(n) for average and in worst cases like where all chars are same for pattern and text string it can go upto O(n-m)*m (i.e)quadratic

*/
#include <iostream>
#include <algorithm>
#include <vector>
#define d 256
const int q = 101;
using namespace std;

vector<int> RbAlgo(string &txt, string &pat)
{
    vector<int> v;
    // compute d^m-1
    int n = txt.length();
    int m = pat.length();
    int h = 1;
    for (int i = 1; i <= m - 1; i++)
        h = (h * d) % q;
    // compute hash of pattern and first window of text
    int p = 0, t = 0;
    for (int i = 0; i < m; i++)
    {
        p = (p * d + pat[i]) % q;
        t = (t * d + txt[i]) % q;
    }

    // check for hits
    for (int i = 0; i <= n - m; i++)
    {
        if (p == t)
        {
            bool flag = true;
            for (int j = 0; j < m; j++)
            {
                if (pat[j] != txt[i + j])
                {
                    flag = false;
                    break;
                }
            }
            if (flag == true)
                v.push_back(i);
        }
        // compute next window hashes
        if (i < (n - m))
        {
            t = ((d * (t - txt[i] * h)) + txt[i + m]) % q;
            if (t < 0)
                t = t + q;
        }
    }
    return v;
}

int main()
{
    string txt = "GEEKS FOR GEEKS";
    string pat = "GEEK";
    vector<int> v = RbAlgo(txt, pat);
    for (auto i : v)
        cout << i << " ";
    return 0;
}