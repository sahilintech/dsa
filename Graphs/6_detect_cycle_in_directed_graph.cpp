/*
Detect cycle in directed graph using dfs

*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

bool detectCycleInDirectedGraph(vector<int> adj[], bool visited[], bool callStack[], int s)
{
    visited[s] = true;
    callStack[s] = true;
    for (int i : adj[s])
    {
        if (visited[i] == false && detectCycleInDirectedGraph(adj, visited, callStack, i) == true)
            return true;
        else if (callStack[i] == true)
            return true;
    }
    callStack[s] = false;
    return false;
}

int main()
{
    int V = 6;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 2, 1);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 5);
    addEdge(adj, 5, 3);
    bool *visited = new bool[V];
    bool *callStack = new bool[V];
    bool result;
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
        callStack[i] = false;
    }
    for (int i = 0; i < V; i++)
    {
        for (int s : adj[i])
        {
            if (visited[s] == false)
                result = detectCycleInDirectedGraph(adj, visited, callStack, s);
        }
    }
    cout<<result;
    return 0;
}