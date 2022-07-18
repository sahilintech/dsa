/*
Count the no. of nodes in binary tree
Time: O(n)
Space: O(h)
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

int sizeOfBinaryTree(Node *root)
{
    if (root == NULL)
        return 0;
    else
        return 1 + (sizeOfBinaryTree(root->left) + sizeOfBinaryTree(root->right));
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right = new Node(30);
    root->right->right = new Node(70);
    cout << sizeOfBinaryTree(root);
    return 0;
}