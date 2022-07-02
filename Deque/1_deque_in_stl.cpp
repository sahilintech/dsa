#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
int main()
{
    deque<int> dq = {10, 20, 30};
    auto it = dq.begin();
    it++;
    dq.insert(it, 46); // will be insert at 2nd position because it is pointing there
    dq.push_back(40);
    dq.push_front(5);
    cout << dq.front()<<endl;
    cout << dq.back()<<endl;
    dq.pop_back();
    dq.pop_front();
    for (auto x : dq)
        cout << x << " ";
    cout << endl;
    cout << dq.size();
    return 0;
}