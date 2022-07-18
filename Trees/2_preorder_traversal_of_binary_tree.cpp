/*
Print the preorder traversal of binary tree

I/p : 10, 20, 30, 40, 50
O/p : 10, 20, 30, 40, 50

Time : O(n)
Space : O(h)
*/

#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    int key;
    Node *left;
    Node *right;
    Node(int k)
    {
        key = k;
        left = right = NULL;
    }
};

void preorder(Node *root)
{
    if (root != NULL)
    {
        cout << root->key << " "; // print current root
        preorder(root->left); // go to root's left
        preorder(root->right); // go to root's right
    }
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);
    preorder(root);
    return 0;
}