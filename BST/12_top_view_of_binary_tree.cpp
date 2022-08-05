/*
Given a bst. Print the top view of bst

Time: 0(n)
Space: 0(n)
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
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

void printTopViewOfBST(Node *root, map<int, int> &m)
{
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    while (q.empty() == false)
    {
        auto p = q.front();
        q.pop();
        Node *curr = p.first;
        int sec = p.second;
        m.insert({sec, curr->key});
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
    root->left->left = new Node(30);
    root->left->right = new Node(40);
    root->right = new Node(50);
    root->right->right = new Node(70);
    root->right->left = new Node(60);
    map<int, int> m;
    printTopViewOfBST(root, m);
    for (auto i : m)
        cout << i.second << " ";
    return 0;
}