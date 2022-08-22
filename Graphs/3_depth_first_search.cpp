/* Traverse the graph in recursive way

1st version = Given an undirected graph and a source vertex 's', print BFS from the given source


#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <limits.h>
#include <stack>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfs(vector<int> adj[], int s, bool visited[])
{
    visited[s] = true;
    cout<<s<<" ";
    for(int i: adj[s])
    {
        if(visited[i]==false)
            dfs(adj, i, visited);
    }
}

int main()
{
    int v = 5;
    vector<int> adj[v];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 3, 4);
    bool *visited = new bool[v];
    int s = 0;
    for (int i = 0; i < v; i++)
        visited[i] = false;
    dfs(adj, s, visited);
    return 0;
}
*/

/* 2nd version = No source given and graph may be disconnected
 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfs(vector<int> adj[], int s, bool visited[])
{
    visited[s] = true;
    cout << s << " ";
    for (int i : adj[s])
    {
        if (visited[i] == false)
            dfs(adj, i, visited);
    }
}
int main()
{
    int v = 5;
    vector<int> adj[v];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 3, 4);
    bool *visited = new bool[v];
    for (int i = 0; i < v; i++)
        visited[i] = false;
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
            dfs(adj, i, visited);
    }
    return 0;
}
// for no. of connected components do same as bfs use count var