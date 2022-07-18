/*
Print all leftmost nodes of binary tree

Time : 0(n)
Space : 0(width) or O(n)
*/
#include <iostream>
#include <algorithm>
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

void printLeftView(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    cout << root->key << " ";
    while (q.size() > 1)
    {
        Node *curr = q.front();
        q.pop();
        if (curr == NULL)
        {
            cout << q.front()->key << " ";
            q.push(NULL);
            continue;
        }
        if (curr->left != NULL)
            q.push(curr->left);
        if (curr->right != NULL)
            q.push(curr->right);
    }
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(50);
    root->right = new Node(60);
    root->right->left = new Node(70);
    root->right->right = new Node(20);
    root->right->right->left = new Node(8);
    printLeftView(root);
    return 0;
}