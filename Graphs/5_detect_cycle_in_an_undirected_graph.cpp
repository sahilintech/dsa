#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool cycleDetection(vector<int> adj[], bool visited[], int parent, int s)
{
    visited[s] = true;
    for (int i : adj[s])
    {
        if (visited[i] == false)
        {
            if (cycleDetection(adj, visited, s, i)==true)
                return true;
        }
        else if (parent != i)
            return true;
    }
    return false;
}

int main()
{
    int v = 6;
    vector<int> adj[v];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 4);
    addEdge(adj, 4, 5);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 3);
    bool *visited = new bool[v];
    for (int i = 0; i < v; i++)
        visited[i] = false;
    for (int i = 0; i < v; i++)
        if (visited[i] == false)
            cout << cycleDetection(adj, visited, -1, i);
    return 0;
}