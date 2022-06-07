/*
Vector implementatin of stack
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct MyStack
{
    vector<int> v;
    void push(int x)
    {
        v.push_back(x);
    }
    int pop()
    {
        int res = v.back();
        v.pop_back();
        return res;
    }
    int peek()
    {
        return v.back();
    }
    int size()
    {
        return v.size();
    }
    int isEmpty()
    {
        return v.empty();
    }
};
int main()
{
    MyStack s;
    s.push(1);
    s.push(2);
    cout<<s.peek()<<endl;
    s.push(3);
    cout<<s.peek()<<endl;
    cout<<s.isEmpty();
    return 0;
}