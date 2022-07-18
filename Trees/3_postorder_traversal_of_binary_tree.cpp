/*
Print the preorder traversal of binary tree

I/p : 10, 20, 30, 40, 50
O/p : 20, 40, 50, 30, 10

Time : O(n)
Space : O(h)
*/

#include<iostream>
#include<algorithm>
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

void postorder(Node *root)
{
    if(root!=NULL)
    {
        postorder(root->left); // first traverse current root's left
        postorder(root->right); // then traverse current root's right
        cout<<root->key<<" "; // print current root
    }
}

int main(){
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);
    postorder(root);
    return 0;
}