// Check whether string is palindrome or not using recursion
#include<iostream>
#include<string>
using namespace std;

bool isPalindrome(string &str, int start, int end){
    if(start>=end)
    return true;
    return (str[start]==str[end]) && isPalindrome(str, start+1, end-1);
}

int main(){
    string str;
    getline(cin, str);
    int n;
    n = str.length();
    int a = isPalindrome(str, 0, n-1);
    cout<<a;
    return 0;
}