/*
Given a text and pattern. Check if any permutaion of pattern exits in text

I/p : text = geeksforgeeks, pat = frog
O/p : Yes (forg is permutation of frog)

I/p : text = geeksforgeeks, pat = rseek
O/p : NO (chars are not present contiguous, s is present far from other chars)


// ***********  Naive Solution *************
// Time : O(n-m)*m

#include <iostream>
#include <algorithm>
using namespace std;

const int CHAR = 256;

bool checkAnagram(string text, string pat, int i)
{
    int count[CHAR] = {0};
    for (int j = 0; j < pat.length(); j++)
    {
        count[pat[j]]++;
        count[text[i + j]]--; // i+j because first we will do for first 4char of text starting from 1 then for next 4 starting from 2
    }
    for (int j = 0; j < CHAR; j++)
        if (count[j] != 0)
            return false;
    return true;
}

bool anagramSearch(string text, string pat)
{
    int n = text.length();
    int m = pat.length();
    for (int i = 0; i < n - m; i++)
    {
        if (checkAnagram(text, pat, i)) // check for every text length equal to pattern length using anagram function
            return true;
    }
    return false;
}

int main()
{
    string text = "geeksforgeeks";
    string pat = "ksof";
    cout<<anagramSearch(text, pat);
    return 0;
}
*/

// Efficient Code
// Time: O(m+(n-m)*CHAR), O(n*CHAR) because m is smaller than n

#include <iostream>
#include <algorithm>
using namespace std;

const int CHAR = 256;

bool areSame(int countPattern[], int countText[])
{
    for (int i = 0; i < CHAR; i++)
        if (countText[i] != countPattern[i]) // if there is any mismatch in char count return false
            return false;
    return true;
}

bool anagramSearch(string text, string pat)
{
    int countText[CHAR] = {0};
    int countPattern[CHAR] = {0};
    for (int i = 0; i < pat.length(); i++)
    {
        countPattern[pat[i]]++; // make array of pattern counts for all chars
        countText[text[i]]++; // make count array of text counts for first chars equal to pattern length
    }
    for (int i = pat.length(); i < text.length(); i++)
    {
        if (areSame(countPattern, countText)) // check if count of both arrays are same then pattern found
            return true;
        countText[text[i]]++; // add next char to text
        countText[text[i - pat.length()]]--; // remove starting char from text
    }
    return false;
}

int main()
{
    string text = "geeksforgeeks";
    string pat = "ksof";
    cout << anagramSearch(text, pat);
    return 0;
}