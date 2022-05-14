/*
Given two strings a text string and a pattern string. We need to return the indices of text string on which pattern string appears

I/p : text = "ABABABCD"
      pattern = "ABAB"

O/p : 0, 2

I/p : text = "AAAAA"
      pattern = "AAA"

O/p : 0, 1, 2

Time : O(n-m + 1)*m
Space : O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> naivePatternSearching(string text, string pattern)
{
    vector<int> v;
    for (int i = 0; i <= text.length() - pattern.length(); i++)
    {
        int j;
        for (j = 0; j < pattern.length(); j++)
        {
            if (pattern[j] != text[i + j]) // if at any point pattern char does not match with text char break
                break;
        }
        if (j == pattern.length()) // if inner loop run pattern string length times means that times pattern chars were equal to text chars then push index to vector
            v.push_back(i);
    }
    return v;
}

int main()
{
    string text = "AAAAA";
    string pattern = "AAA";
    vector<int> v = naivePatternSearching(text, pattern);
    for (auto i : v)
        cout << i << " ";
    return 0;
}