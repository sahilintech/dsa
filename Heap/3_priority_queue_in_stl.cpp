/*
Priority queue in stl
*/

#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int main(){
    priority_queue<int> pq; // by default it implements max heap i.e pq.top() will always gives max element
    // if we want to implement min heap i.e pq.top() will give min element
    // we will declare as priority_queue<int, vector<int>, greater<int>> pq; 
    pq.push(10);
    pq.push(15); // O(log n)
    pq.push(5);
    cout<<pq.size()<<" ";
    cout<<pq.top()<<" "; // O(1)
    cout<<endl;
    while(pq.empty() == false)
    {
        cout<<pq.top()<<" "; // O(1)
        pq.pop(); // O(log n)
    }
    return 0;
}