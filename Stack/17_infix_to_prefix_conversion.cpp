#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <limits.h>
#include <stack>
using namespace std;

int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '-' || c == '+')
        return 1;
    else
        return -1;
}

void infixToPrefix(string exp)
{
    stack<char> s;
    string result;
    for (int i = exp.length() - 1; i >= 0; i--)
    {
        char c = exp[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            result += c;
        else if (c == ')')
            s.push(c);
        else if (c == '(')
        {
            while (s.top() != ')')
            {
                result += s.top();
                s.pop();
            }
            s.pop(); // remove ')' also
        }
        else
        {
            while (!s.empty() && prec(exp[i]) < prec(s.top()))
            {
                if (c == '^' && s.top() == '^')
                    break;
                else
                {
                    result += s.top();
                    s.pop();
                }
            }
            s.push(c);
        }
    }
    while (!s.empty())
    {
        result += s.top();
        s.pop();
    }

    reverse(result.begin(), result.end());
    cout<<result;
}

int main()
{
    string exp = "a+b*(c+d-e)^(f+g*h)-i";
    infixToPrefix(exp);
    return 0;
}
