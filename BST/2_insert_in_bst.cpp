/*
Given a binary tree. Insert a val in it

Time : O(h)
Space : O(h)
*/

#include <iostream>
#include <algorithm>
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

/* recursive
Node *insertInBST(Node *root, int x)
{
    if (root == NULL)
    {
        return new Node(x);
    }
    else if (root->key > x)
        root->left = insertInBST(root->left, x);
    else
        root->right = insertInBST(root->right, x);
    return root;
}
*/

// iterative
Node *insertInBST(Node *root, int x)
{
    Node *temp = new Node(x);
    Node *curr = root;
    Node *parent = NULL;
    while (curr != NULL)
    {
        parent = curr;
        if (curr->key > x)
            curr = curr->left;
        else
            curr = curr->right;
    }
    if(parent == NULL) // if only null is present in tree
        return temp;
    else if(parent->key > x)
        parent->left = temp;
    else
        parent->right = temp;
    return root;
}

void traverseBinaryTree(Node *root)
{
    if (root != NULL)
    {
        cout << root->key << " ";
        traverseBinaryTree(root->left);
        traverseBinaryTree(root->right);
    }
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->right->left = new Node(12);
    root->right->right = new Node(18);
    int x = 20;
    Node *newRoot = insertInBST(root, x);
    traverseBinaryTree(newRoot);
    return 0;
}