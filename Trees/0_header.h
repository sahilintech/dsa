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
int heightOfTree(Node *root)
{
    if (root == NULL)
        return 0;
    else
        return max(heightOfTree(root->right), heightOfTree(root->left)) + 1;
}