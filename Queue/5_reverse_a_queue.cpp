/*
Given a queue reverse it

********* Recursive Implementation **********
#include <bits/stdc++.h>
#include <queue>
using namespace std;


void Print(queue<int>& Queue)
{
    while (!Queue.empty()) {
        cout << Queue.front() << " ";
        Queue.pop();
    }
}


void reverse(queue<int>& q)
{
    if(q.empty())
       return;

    int x = q.front();
     q.pop();

   reverse(q);
   q.push(x);
}


int main()
{
    queue<int> q;
    q.push(12);
    q.push(5);
    q.push(15);
    q.push(20);

    reverse(q);
    Print(q);
}

*/

// ************** Iterative Solution **************
#include <iostream>
#include <algorithm>
#include <limits.h>
#include <stack>
#include <queue>
using namespace std;

void printQueue(queue<int> &q)
{
    while (q.empty() == 0)
    {
        cout << q.front() << " ";
        q.pop();
    }
}

void reverseQueue(queue<int> &q)
{
    stack<int> st;
    // push queue elements to stack
    while (q.empty() == 0)
    {
        st.push(q.front());
        q.pop();
    }
    // push back stack elements to queue
    while (st.empty() == 0)
    {
        q.push(st.top());
        st.pop();
    }
}

int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    reverseQueue(q);
    printQueue(q);
    return 0;
}