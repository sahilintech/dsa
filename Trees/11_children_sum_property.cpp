/*
Sum of childrens of every node should be equal to its parent node

Time : 0(n)
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

bool checkChildrenSumProperty(Node *root)
{

    if (root == NULL)
        return true;
    if (root->left == NULL && root->right == NULL)
        return true;
    int sum = 0;
    if (root->left != NULL)
        sum += root->left->key;
    if (root->right != NULL)
        sum += root->right->key;
    return (root->key == sum && checkChildrenSumProperty(root->left) && checkChildrenSumProperty(root->right));
}

int main()
{
    Node *root = new Node(20);
    root->left = new Node(8);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    root->right = new Node(12);
    cout << checkChildrenSumProperty(root);
    return 0;
}