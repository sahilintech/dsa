/*
Do preorder traversal of binary tree in iterative way

Time : O(n)
Space : O(h)
*/
#include <iostream>
#include <algorithm>
#include <stack>
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

void preorderTraversal(Node *root)
{
    if (root == NULL)
        return;
    stack<Node *> st;
    Node *curr = root;
    while (curr != NULL || st.empty() == false)
    {
        while (curr != NULL)
        {
            st.push(curr);
            cout << curr->key << " ";
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        curr = curr->right;
    }
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->left->left = new Node(40);
    root->right = new Node(30);
    root->right->left = new Node(60);
    preorderTraversal(root);
    return 0;
}