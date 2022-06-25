#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <limits.h>
#include <stack>
using namespace std;

double evaluationOfPostfixExp(string exp)
{
    int o1, o2;     
    stack<double> st;
    for (double i = 0; i < exp.size(); i++)
    {
        if (exp[i] == ' ')
            continue;
        if (isdigit(exp[i]))
        {
            double num = 0, j = i;
            while (i >= 0 && isdigit(exp[i]))
                i++;
            i--;
            for (int k = j; k <= i; k++)
                num = num * 10 + double(exp[k] - '0');
            st.push(num);
        }
        else
        {
            o1 = st.top();
            st.pop();
            o2 = st.top();
            st.pop();

            switch (exp[i])
            {
            case '+':
                st.push(o2 + o1);
                break;

            case '-':
                st.push(o2 - o1);
                break;

            case '*':
                st.push(o2 * o1);
                break;

            case '/':
                st.push(o2 / o1);
                break;
            }
        }
    }
    return st.top();
}

int main()
{
    string exp = "100 200 + 2 / 5 * 7 +";
    cout << evaluationOfPostfixExp(exp);
    return 0;
}