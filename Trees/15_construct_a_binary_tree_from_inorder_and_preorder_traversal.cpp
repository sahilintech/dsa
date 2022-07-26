/*

Given two arrays containing prorder and inorder traversal. Construct a binary tree from them

I/p = in[] = {20, 10, 40, 30, 50}
    pre[] = {10, 20, 30, 40, 50}

O/p : Binary tree

Time : O(n^2)

For doing it in O(n) use hashmap to store the indexes of inorder array so we do not need to find by taking loop inside function
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

Node *constructBT(int in[], int pre[], int ins, int ine)
{
    static int preIndex = 0;
    if (ins > ine)
        return NULL;
    Node *root = new Node(pre[preIndex++]);
    int inIndex;
    for (int i = ins; i <= ine; i++)
    {
        if (in[i] == root->key)
        {
            inIndex = i;
            break;
        }
    }
    root->left = constructBT(in, pre, ins, inIndex - 1);
    root->right = constructBT(in, pre, inIndex + 1, ine);
    return root;
}

void printInorderTree(Node *root)
{
    if (root != NULL)
    {
        printInorderTree(root->left);
        cout << root->key << " ";
        printInorderTree(root->right);
    }
}

int main()
{
    int in[] = {20, 10, 40, 30, 50};
    int pre[] = {10, 20, 30, 40, 50};
    int n = sizeof(in) / sizeof(in[0]);
    Node *root = constructBT(in, pre, 0, n - 1);
    printInorderTree(root);
    return 0;
}