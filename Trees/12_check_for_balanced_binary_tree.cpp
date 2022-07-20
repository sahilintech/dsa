/*
Given a tree. For every node check if it is balanced or not.
A node is called balanced if difference between heights of its left and right subtree is not greater than 1

Time : O(n)
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

int checkIfBalanced(Node *root)
{
    if (root == NULL)
        return 0;
    int lh = checkIfBalanced(root->left);
    if (lh == -1)
        return -1;
    int rh = checkIfBalanced(root->right);
    if (rh == -1)
        return -1;
    if (abs(lh - rh) > 1)
        return -1;
    else
        return max(lh, rh) + 1;
}

int main()
{
    Node *root = new Node(30);
    root->left = new Node(40);
    root->right = new Node(20);
    root->right->left = new Node(13);
    root->right->right = new Node(70);
    int sol = checkIfBalanced(root);
    if (sol == -1)
        cout << "No";
    else
        cout << "Yes";
    return 0;
}