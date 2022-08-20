/*
1st version = Given an undirected graph and a source vertex 's', print BFS from the given source

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

void addEdge(vector<int> adj[], int V, int U)
{
    adj[V].push_back(U);
    adj[U].push_back(V);
}

void bfs(vector<int> adj[], int v, int s)
{
    bool *visited = new bool[v];
    for (int i = 0; i < v; i++)
        visited[i] = false;
    queue<int> q;
    visited[s] = true;
    q.push(s);
    while(q.empty() == false)
    {
        int u = q.front();
        q.pop();
        cout<<u<<" ";
        for(int v: adj[u]) // push all adjacents of vertex v into queue
        {
            if(visited[v] == false) // avoiding already occured verices
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int main()
{
    int V = 5;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 1, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 2, 4);
    int source = 0;
    bfs(adj, V, source);
    return 0;
}
*/

/* 2nd version = No source given and graph may be disconnected
 Just traverse each vertex one by one by using for loop for traversing the graph vertices
 Time : O(v+e) no. of vertices and edges
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void bfs(vector<int> adj[], int s, bool visited[])
{
    queue<int> q;
    visited[s] = true;
    q.push(s);
    while (q.empty() == false)
    {
        int u = q.front();
        cout << u << " ";
        q.pop();
        for (int i : adj[u])
        {
            if (visited[i] == false)
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int main()
{
    int v = 7;
    vector<int> adj[v];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 1, 3);
    addEdge(adj, 4, 5);
    addEdge(adj, 5, 6);
    addEdge(adj, 4, 6);
    bool *visited = new bool[v];
    for (int i = 0; i < v; i++)
        visited[i] = false;
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
        {
            bfs(adj, i, visited);
        }
    }
    return 0;
}
*/
// No. of islands in a graph

// No. of connnected components in an undirected graph

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

void addEdge(vector<int> adj[], int v, int u)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void countConnectedComponents(vector<int> adj[], int s, bool visited[])
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while (q.empty() == false)
    {
        int u = q.front();
        q.pop();
        for (int i : adj[u])
        {
            if (visited[i] == false)
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main()
{
    int v = 7;
    vector<int> adj[v];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 1, 3);
    addEdge(adj, 4, 5);
    addEdge(adj, 5, 6);
    addEdge(adj, 4, 6);
    bool *visited = new bool[v];
    int count = 0;
    for (int i = 0; i < v; i++)
        visited[i] = false;
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
        {
            countConnectedComponents(adj, i, visited);
            count++;
        }
    }
    cout << count;
    return 0;
}