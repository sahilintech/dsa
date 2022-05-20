/*
Given two strings check if these are rotations of each other or not

I/p : s1 = "ABCD", s2 = "CDAB"
O/p : Yes (Given string s1 can be rotated 2 times to obtain string s2)

I/p : s1 = "ABAAA", s2 = "BAAAA"
O/p : Yes

Time : O(n)
*/

#include <iostream>
#include <algorithm>
using namespace std;

bool checkRotation(string &s1, string &s2)
{
    if (s1.length() != s2.length())
        return false;
    return ((s1 + s1).find(s2) != string::npos); // if we will concatenate one string with itself then other string will be found in concatenation of first string if it is rotation.
}

int main()
{
    string s1 = "ABCD";
    string s2 = "CADB";
    cout << checkRotation(s1, s2);
    return 0;
}