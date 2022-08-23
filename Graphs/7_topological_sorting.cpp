/*
Given a directed acyclic graph. We need to find topological sorting

In topological sorting edges are considered as dependencies and nodes are considered as jobs

Jobs which will have 0 dependencies i.e(0 indegree will be printed first) then others
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

void topologicalSort(vector<int> adj[], int v)
{
    vector<int> indegree(v, 0);
    for (int i = 0; i < v; i++)
        for (int x : adj[i])
            indegree[x]++;
    queue<int> q;
    for (int i = 0; i < v; i++)
        if (indegree[i] == 0)
            q.push(i);
    while (q.empty() == false)
    {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int i : adj[u])
        {
            indegree[i] = indegree[i] - 1;
            if (indegree[i] == 0)
                q.push(i);
        }
    }
}

int main()
{
    int V = 5;
    vector<int> adj[V];
    addEdge(adj, 0, 2);
    addEdge(adj, 0, 3);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    topologicalSort(adj, V);
    return 0;
}