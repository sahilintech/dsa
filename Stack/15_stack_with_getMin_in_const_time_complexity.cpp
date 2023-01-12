// Design a stack that supports getMin function in O(1) time complexity
// Time : O(1), Space: O(n)
/*
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

struct MyStack
{
    stack<int> ms;
    stack<int> as;
    void push(int x)
    {
        if (ms.empty()) // if 1st element push to both stacks
        {
            ms.push(x);
            as.push(x);
            return;
        }
        ms.push(x);
        if (ms.top() <= as.top()) // if min element is pushed in main stack push it also to aux stack also equal elements to be pushed
            as.push(x);
    }
    void pop()
    {
        if (as.top() == ms.top()) // if top of both stacks equal remove from both
            as.pop();
        ms.pop();
    }

    int getMin()
    {
        return as.top(); // top of aux stack will always be min
    }
};

int main()
{
    MyStack s;
    s.push(2);
    s.push(3);
    s.push(4);
    cout << s.getMin() << endl;
    s.push(1);
    cout << s.getMin() << endl;
    s.pop();
    cout << s.getMin() << endl;
    return 0;
}
*/

// More efficient solution
// Time : O(1), Space: O(1)

#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
d
struct MyStack
{
    stack<int> s;
    int min, res;
    void push(int x)
    {
        if (s.empty())
        {
            min = x;
            s.push(x);
        }
        else if (x <= min)
        {
            s.push(2 * x - min);
            min = x;
        }
        else
            s.push(x);
    }

    int pop()
    {
        int tp = s.top();
        s.pop();
        if (tp <= min)
        {
            res = min;
            min = 2 * min - tp;
            return res;
        }
        else
            return tp;
    }
    int getMin()
    {
        return min;
    }

    int top()
    {
        int tp = s.top();
        return (tp <= min ? min : tp);
    }
};

int main()
{
    MyStack s;
    s.push(2);
    s.push(3);
    s.push(4);
    cout << s.getMin() << endl;
    s.push(1);
    cout << s.getMin() << endl;
    s.pop();
    cout << s.getMin() << endl;
    return 0;
}
