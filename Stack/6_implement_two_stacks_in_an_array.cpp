/*
We are given an array. We need to implement two stacks in it


// ********* Naive Solution ************


Divide array in two halves for two stacks but the solution is not space efficient

#include <iostream>
#include <algorithm>
using namespace std;

struct TwoStacks
{
    int *arr;
    int cap;
    int top1, top2;
    TwoStacks(int n)
    {
        cap = n;
        arr = new int[n];
        top1 = n / 2 + 1;
        top2 = n / 2;
    }
    void push1(int x)
    {
        if (top1 > 0)
        {
            top1--;
            arr[top1] = x;
        }
        else
        {
            cout << "Stack Overflow";
            return;
        }
    }
    void push2(int x)
    {
        if (top2 < cap - 1)
        {
            top2++;
            arr[top2] = x;
        }
        else
        {
            cout << "Stack Overflow";
            return;
        }
    }
    int pop1()
    {
        if (top1 <= cap / 2)
        {
            int x = arr[top1];
            top1++;
            return x;
        }
        else
        {
            cout << "Stack Underflow" << endl;
            exit(1);
        }
    }

    int pop2()
    {
        if (top2 >= cap / 2 + 1)
        {
            int x = arr[top2];
            top2--;
            return x;
        }
        else
        {
            cout << "Stack Underflow" << endl;
            exit(1);
        }
    }
};

int main()
{
    TwoStacks s(5);
    s.push1(2);
    s.push2(3);
    s.pop1();
    s.pop1();
    return 0;
}

*/

// *********** Space Efficient Solution ****************

// Start both the stacks from both ends of array for space efficiency

#include <iostream>
#include <algorithm>
using namespace std;

struct TwoStacks
{
    int *arr;
    int cap;
    int end1, end2;
    TwoStacks(int n)
    {
        cap = n;
        arr = new int[n];
        end1 = -1;
        end2 = n;
    }
    void push1(int x)
    {
        if (end1 < end2 - 1)
        {
            end1++;
            arr[end1] = x;
        }
        else
        {
            cout << "Stack Overflow";
            return;
        }
    }
    void push2(int x)
    {
        if (end2 > end1 + 1)
        {
            end2--;
            arr[end2] = x;
        }
        else
        {
            cout << "Stack Overflow";
            return;
        }
    }
    int pop1()
    {
        if (end1 > -1)
        {
            int x = arr[end1];
            end1--;
            return x;
        }
        else
        {
            cout << "Stack Underflow";
            exit(1);
        }
    }
    int pop2()
    {
        if (end2 < cap)
        {
            int x = arr[end2];
            end2++;
            return x;
        }
        else
        {
            cout << "Stack Underflow";
            exit(1);
        }
    }
};

int main()
{
    TwoStacks ts(5);
    ts.push1(5);
    ts.push2(10);
    ts.push2(15);
    ts.push1(11);
    ts.push2(7);
    cout << "Popped element from stack1 is " << ts.pop1();
    ts.push2(40);
    cout << "\nPopped element from stack2 is " << ts.pop2();
    return 0;
}