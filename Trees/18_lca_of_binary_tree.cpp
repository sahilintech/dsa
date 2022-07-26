/*

Print least common ancestor of binary tree
We will be given two nodes print their least common ancestor

Time : O(n)
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

Node *findLCA(Node *root, int n1, int n2)
{
    if (root == NULL)
        return NULL;
    if (root->key == n1 || root->key == n2)
        return root;
    Node *lca1 = findLCA(root->left, n1, n2);
    Node *lca2 = findLCA(root->right, n1, n2);

    if (lca1 != NULL && lca2 != NULL)
        return root;
    if (lca1 != NULL)
        return lca1;
    else
        return lca2;
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);
    int n1 = 40;
    int n2 = 50;
    Node *node = findLCA(root, n1, n2);
    cout<<node->key;
    return 0;
}