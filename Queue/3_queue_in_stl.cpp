#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int main()
{
    // deletion front front and insertion to end
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.pop();
    cout<<q.front()<<endl;
    cout<<q.back()<<endl;
    cout<<q.empty()<<endl;
    cout<<q.size()<<endl;
    return 0;
}