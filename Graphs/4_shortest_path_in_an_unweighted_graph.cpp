/*
Given an unweighted graph. Print distance of path from source vertex to every vertex

As we are using bfs for finding the adjacents and then using distance array to find the distances so time complexity will be same as bfs

Time : O(v+e)
*/

#include <iostream>
#include <algorithm>
#include <limits.h>
#include <vector>
#include <queue>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[v].push_back(u);
    adj[u].push_back(v);
}

void shortestPathDFS(vector<int> adj[], vector<int> &dist, bool visited[], int s)
{
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    visited[s] = true;
    while (q.empty() == false)
    {
        int u = q.front();
        q.pop();
        for (int i : adj[u])
        {
            if (visited[i] == false)
            {
                dist[i] = dist[u] + 1;
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int main()
{
    int v = 4;
    vector<int> adj[v];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    vector<int> dist(v);
    bool *visited = new bool[v];
    for (int i = 0; i < v; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = false;
    }
    int s = 0;
    shortestPathDFS(adj, dist, visited, s);
    for(int i: dist)
    {
        cout<<i<<" ";
    }
    return 0;
}