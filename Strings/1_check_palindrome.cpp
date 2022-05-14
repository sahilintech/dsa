/*
Given a string. Check the string is palindrome or no i.e(reads same from start and end)
I/p : "abba"
O/p : Yes

I/p : "sahil"
O/p : No

Time : O(n)
Space: O(1)
*/


#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool checkPalindrome(string &str)
{
    int begin=0;
    int end=str.length()-1;
    while(begin<end)
    {
        if(str[begin]!=str[end]) // iterate from both ends return false if there is a mismatch in pattern of characters
        return false;
        begin++;
        end--;
    }
    return true;
}

int main(){
    string str = "abccba";
    if(checkPalindrome(str))
    cout<<"Yes";
    else
    cout<<"No";
    return 0;
}