/*
Given two strings. Check if both strings are anagram of each other i.e(Every char should be same in both strings and frequency of each char should also be same but they can differ in their order)

I/p : s1 = "listen" , s2 = "tenlis"
O/p : Yes

I/p : s1 = "aba" , s2 = "bab"
O/p : No

Time = O(n)
Space = O(CHAR)
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int CHAR = 256;
bool checkAnagram(string str1, string str2)
{
    if (str1.length() != str2.length())
        return false;
    int count[CHAR] = {0}; // create an empty array with elements equal to zero of size 256
    for (int i = 0; i < str1.length(); i++)
    {
        count[str1[i]]++;  
        count[str2[i]]--;
    }
    // now here above if two string are anagram every index of count array should contain zero after these above two operations
    for (int i = 0; i < CHAR; i++)
        if (count[i] != 0)
            return false;
    return true;
}

int main()
{
    string str1 = "listen";
    string str2 = "tenlis";
    if (checkAnagram(str1, str2))
        cout << "Yes";
    else
        cout << "No";
    return 0;
}