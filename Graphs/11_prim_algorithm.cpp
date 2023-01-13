/*
Given a weighted and connected undirected graph.Print minimum spanning tree of it.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
using namespace std;

void primMst(vector<pair<int, int>> adj[], int N)
{
    int parent[N];
    int key[N];
    bool mstSet[N];

    for (int i = 0; i < N; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;
    for (int count = 0; count < N - 1; count++)
    {
        int mini = INT_MAX, u;
        for (int v = 0; v < N; v++) // iterate through all keys and pick out the minimum key(i.e vertex) from key array
        {
            if (mstSet[v] == false && key[v] < mini)
                mini = key[v], u = v;
        }
        mstSet[u] = true;

        for (auto it : adj[u]) // iterate through all adjacents of current minimum key
        {
            int v = it.first;
            int weight = it.second;
            if (mstSet[v] == false && weight < key[v]) // update parent of current key 
                parent[v] = u, key[v] = weight;
        }
    }
    int sum = 0;
    for (int i = 1; i < N; i++)
    {
        cout << parent[i] << " - " << i << " \n";
        sum = sum + key[i];
    }
    cout<<"Weight of graph is "<<sum<<endl;
}

int main()
{
    int N = 5;
    vector<pair<int, int>> adj[N];
    adj[0].push_back({1, 2});
    adj[0].push_back({3, 6});
    adj[1].push_back({0, 2});
    adj[1].push_back({2, 3});
    adj[1].push_back({3, 8});
    adj[1].push_back({4, 5});
    adj[2].push_back({1, 3});
    adj[2].push_back({4, 7});
    adj[3].push_back({0, 6});
    adj[3].push_back({1, 8});
    adj[4].push_back({1, 5});
    adj[4].push_back({2, 7});
    primMst(adj, N);
    return 0;
}

