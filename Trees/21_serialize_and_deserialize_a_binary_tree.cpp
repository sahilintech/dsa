#include <iostream>
#include <algorithm>
#include <vector>
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

void serializeBT(Node *root, vector<int> &v)
{
    if(root == NULL)
    {
        v.push_back(-1);
        return;
    }
    v.push_back(root->key);
    serializeBT(root->left, v);
    serializeBT(root->right, v);
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->left->left = new Node(40);
    root->left->left->left = new Node(80);
    root->right = new Node(30);
    root->right->left = new Node(50);
    root->right->right = new Node(60);
    vector<int> v;
    serializeBT(root, v);
    for(auto i: v)
    cout<<i<<" ";
    return 0;
}