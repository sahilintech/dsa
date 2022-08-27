// Topological sorting is kahn's algorithm
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

bool detectCycle(vector<int> adj[], int v)
{
    vector<int> indegree(v, 0);
    for (int u = 0; u < v; u++)
    {
        for (int i : adj[u])
        {
            indegree[i]++;
        }
    }
    queue<int> q;
    int count = 0;
    for (int i = 0; i < v; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    while (q.empty() == false)
    {
        int u = q.front();
        q.pop();
        for (int i : adj[u])
        {
            indegree[i]--;
            if (indegree[i] == 0)
                q.push(i);
        }
        count++;
    }
    return (count != v);
}

int main()
{
    int V = 5;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 4, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 1);
    cout << detectCycle(adj, V);
    return 0;
}