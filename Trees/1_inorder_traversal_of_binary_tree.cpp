/*
Print the inorder traversal of binary tree

I/p : 10, 20, 30, 40, 50
O/p : 20, 10, 40, 30, 50

Time : O(n) // no. of nodes
Space : O(h) // height of tree
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

void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);      // first traverse whole left branch
        cout << root->key << " "; // then start printing
        inorder(root->right);     // then traverse whole right branch
    }
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);
    inorder(root);
    return 0;
}