#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void addEdge(vector<int> adj[], int v, int u)
{
    adj[u].push_back(v); // undirected graph is represented u to v
    adj[v].push_back(u); // v to u
}

int main(){
    int v = 4; // no. of edges
    vector<int> adj[v]; // using array of vectors to represent graph
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    return 0;
}