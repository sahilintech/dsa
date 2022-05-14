// Given two strings a text string and a pattern string. We need to return the indices of text string on which pattern string appears
// Note : Here all the characters of pattern string is different
/*
I/p : text = "ABCABCDABCD"
      pattern = "ABCD"

O/p : 0, 2

I/p : text = "GEEKSFORGEEKS"
      pattern = "EKS"

O/p : 2, 10

Time : O(n-m + 1)*m
Space : O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> naivePatternSearchingForDistinct(string text, string pattern)
{
    vector<int> v;
    for (int i = 0; i <= text.length() - pattern.length();)
    {
        int j;
        for (j = 0; j < pattern.length(); j++)
        {
            if (pattern[j] != text[i + j]) // if at any point pattern char does not match with text char break
                break;
        }
        if (j == pattern.length()) // if inner loop run pattern string length times means that times pattern chars were equal to text chars then push index to vector
            v.push_back(i);

        // since pattern string contains distinct chars if at any point in j loop breaks then for that characters we can skip searching in i;
        if(j==0)
        i++;
        else
        i=i+j;
    }
    return v;
}

int main()
{
    string text = "GEEKSFORGEEKS";
    string pattern = "EKS";
    vector<int> v = naivePatternSearchingForDistinct(text, pattern);
    for (auto i : v)
        cout << i << " ";
    return 0;
}