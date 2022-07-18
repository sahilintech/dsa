/*
Print the key of node having maximum value

Time : O(n)
Space : O(h)
*/
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
int maximumInBinaryTree(Node *root)
{
    if(root == NULL)
        return INT_MIN;
    else
        return max(root->key, max(maximumInBinaryTree(root->left), maximumInBinaryTree(root->right)));
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right = new Node(30);
    root->right->right = new Node(70);
    cout << maximumInBinaryTree(root);
    return 0;
}