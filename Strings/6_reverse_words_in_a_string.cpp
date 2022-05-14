// Given a string reverse the string word by word
/*
I/p : "I love coding"
O/p : "coding love I"

I/p : "geeks for geeks"
O/p : "geeks for geeks"

Time : O(length);
*/

#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

void reverse(char str[], int low, int high)
{
    while (low <= high)
    {
        swap(str[low], str[high]);
        low++;
        high--;
    }
}

void reverseWords(char str[], int n)
{
    int start = 0;
    for (int end = 0; end < n; end++) 
    {
        if (str[end] == ' ') // reverse if we encounter a space and make start = end +1 so it can point to first char of next word
        {
            reverse(str, start, end - 1);
            start = end + 1;
        }
    }
    reverse(str, start, n - 1); // last word is handled explicityly so reverse it
    reverse(str, 0, n - 1); // reverse the whole string
}

int main()
{
    string s = "I love coding";
    int n = s.length();
    char str[n];
    strcpy(str, s.c_str());
    reverseWords(str, n);
    for (int i = 0; i < n; i++)
        cout << str[i];
    return 0;
}