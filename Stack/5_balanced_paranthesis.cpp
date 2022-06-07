/*
We are given a string of six possible chars = '(' ')' '[' ']' '{' '}'
Return true if current opening bracket closes first and so on

I/p : "([])"
O/p : True

I/p : "((())"
O/p : No

I/p : "{}([()])"
O/p : Yes
*/

#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

// matching open brace with closing
bool isMatch(char a, char b)
{
    return ((a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}'));
}

bool balancedString(string str)
{
    stack<char> s;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != ')' && str[i] != ']' && str[i] != '}') // push only open braces in stack
            s.push(str[i]);
        else // if we encounter closing braces compare that char with top of stack if equal remove that open brace from stack to compare next brace
        {
            if (s.empty()) // if this condition is not check underflow error can come for examples like "))("
                return false;
            else if (!isMatch(s.top(), str[i]))
                return false;
            else
                s.pop(); // remove if match is successful
        }
    }
    return (s.empty() == true); // if string contains "((" we will directy come here so we need to check again
}

int main()
{
    string str = "{}([()])";
    cout << balancedString(str);
    return 0;
}