/*
Given a tree check if given tree is bst or not

Time : O(n)
Space: O(h)
*/

// A binary tree is bst iff inorder traversal of it is in increasing order
#include <iostream>
#include <algorithm>
#include <limits.h>
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
int previ = INT_MIN; // making previ var to compare if traversal is in ascending order or not
bool checkBST(Node *root)
{
    if (root == NULL)
        return true;
    if (checkBST(root->left) == false)
        return false;
    if (root->key <= previ)
        return false;
    previ = root->key;
    return (checkBST(root->right));
}

int main()
{
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    cout << checkBST(root);
    return 0;
}