/*
Given a directed acyclic graph. We need to find topological sorting

In topological sorting edges are considered as dependencies and nodes are considered as jobs

Jobs which will have 0 dependencies i.e(0 indegree will be printed first) then others
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <limits.h>
#include <stack>
#include <queue>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

bool topologicalSortingUsingDfs(vector<int> adj[], bool visited[], stack<int> &st, int s)
{
    visited[s] = true;
    for (int i : adj[s])
    {
        if (visited[i] == false)
            topologicalSortingUsingDfs(adj, visited, st, i);
    }
    st.push(s);
}

int main()
{
    int V = 5;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 2, 4);
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    stack<int> st;
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            topologicalSortingUsingDfs(adj, visited, st, i);
    while(st.empty()==false)
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}