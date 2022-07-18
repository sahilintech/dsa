/*
Print every node of tree level by level and also print spaces between every level

Time : 0(n);
Space : O(n);
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

void levelOrderTraversalLineByLine(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (q.size() > 1) // because we will always have one node as NULL in it
    {
        Node *curr = q.front();
        q.pop();
        if (curr == NULL)
        {
            cout << "\n";
            q.push(NULL);
            continue;
        }
        cout << curr->key << " ";
        if (curr->left != NULL)
            q.push(curr->left);
        if (curr->right != NULL)
            q.push(curr->right);
    }
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right = new Node(30);
    root->right->right = new Node(70);
    levelOrderTraversalLineByLine(root);
    return 0;
}