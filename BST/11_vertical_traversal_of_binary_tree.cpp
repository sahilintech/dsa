/*
Given a bst. Print nodes of bst in vertical order

Time: 0(n)
Space: 0(n)
*/

#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

struct Node
{
    int key;
    Node *left, *right;
    Node(int x)
    {
        key = x;
        left = right = NULL;
    }
};

void verticalTraversalOfBST(Node *root, int hd, map<int, vector<int>> &m)
{
    queue<pair<Node *, int>> q;
    q.push({root, hd});
    while (q.empty() == false)
    {
        auto p = q.front();
        q.pop();
        Node *curr = p.first;
        int sec = p.second;
        m[sec].push_back(curr->key);
        if (curr->left != NULL)
            q.push({curr->left, sec - 1});
        if (curr->right != NULL)
            q.push({curr->right, sec + 1});
    }
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    map<int, vector<int>> m;
    verticalTraversalOfBST(root, 0, m);
    for (auto i : m)
    {
        for (int y : i.second)
            cout << y << " ";
        cout << endl;
    }
    return 0;
}