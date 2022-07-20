/*

Given a binary tree. find its maximum width

Time : O(n)
Space: O(h)
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

int maxWidth(Node *root)
{
    int res = 1;
    if (root == NULL)
        return 0;
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (q.size() > 1)
    {
        Node *curr = q.front();
        int n = q.size();
        q.pop();
        if (curr == NULL)
        {
            res = max(n-1, res);
            n=0;
            q.push(NULL);
            continue;
        }

        if (curr->left != NULL)
            q.push(curr->left);
        if (curr->right != NULL)
            q.push(curr->right);
    }
    return res;
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->left->left = new Node(40);
    root->left->left->left = new Node(80);
    root->right = new Node(30);
    root->right->left = new Node(50);
    root->right->right = new Node(60);
    cout << maxWidth(root);
    return 0;
}