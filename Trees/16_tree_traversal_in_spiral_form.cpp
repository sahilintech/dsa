/*
Given a binary tree do level order traversal of this binary tree in spiral form

Time : O(n)
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
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

void printSpiralTree(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    stack<int> s;
    q.push(root);
    bool reverse = false;
    while (q.empty() == false)
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            Node *curr = q.front();
            q.pop();
            if (reverse)
                s.push(curr->key);
            else
                cout << curr->key << " ";
            if (curr->left != NULL)
                q.push(curr->left);
            if (curr->right != NULL)
                q.push(curr->right);
        }
        if (reverse)
        {
            while (s.empty() == false)
            {
                cout << s.top() << " ";
                s.pop();
            }
        }
        reverse = !reverse;
        cout << endl;
    }
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->right = new Node(10);
    printSpiralTree(root);
    return 0;
}