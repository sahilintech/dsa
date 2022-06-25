#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <limits.h>
#include <stack>
using namespace std;

double evaluationOfPrefixExp(string exp)
{
    double o1, o2;
    stack<double> st;
    for (double i = exp.length() - 1; i >= 0; i--)
    {
        if (exp[i] == ' ')
            continue;
        if (isdigit(exp[i])) // if digit push
        {
            // there may be more than
            // one digits in a number
            double num = 0, j = i;
            while (i < exp.size() && isdigit(exp[i]))
                i--;
            i++;

            // from [j, i] exprsn contains a number
            for (int k = i; k <= j; k++)
                num = num * 10 + double(exp[k] - '0');

            st.push(num);
        }
        else // else pop and two items and push their result
        {
            o1 = st.top();
            st.pop();
            o2 = st.top();
            st.pop();

            switch (exp[i])
            {
            case '+':
                st.push(o1 + o2);
                break;
            case '-':
                st.push(o1 - o2);
                break;
            case '*':
                st.push(o1 * o2);
                break;
            case '/':
                st.push(o1 / o2);
                break;
            }
        }
    }
    return st.top(); // at last stack contains the answer
}

int main()
{
    string exp = "+ 9 * 12 6";
    cout << evaluationOfPrefixExp(exp);
    return 0;
}