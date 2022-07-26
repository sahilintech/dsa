/*

Count no. of nodes in a complete binary tree

*/

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct Node
{
    int key;
    Node *right, *left;
    Node(int x)
    {
        key = x;
        left = right = NULL;
    }
};

/* Time : O(n)
int res = 0;
int countNodesInBT(Node *root)
{
    if (root != NULL)
    {
        res++;
        countNodesInBT(root->left);
        countNodesInBT(root->right);
    }
    return res;
}
*/

/// O(log n) * O(log n)
int countNodesInBT(Node *root)
{
    int lh = 0, rh = 0;
    Node *curr = root;
    while(curr != NULL)
    {
        lh++;
        curr = curr->left;
    }
    curr = root;
    while(curr != NULL)
    {
        rh++;
        curr = curr->right;
    }
    if(lh == rh)
        return pow(2,lh)-1;
    return 1+countNodesInBT(root->left)+countNodesInBT(root->right);
}

int main()
{
    Node *root = new Node(10);
    root->right = new Node(30);
    root->left = new Node(20);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    cout << countNodesInBT(root);
    return 0;
}