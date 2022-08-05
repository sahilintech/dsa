/*
Given a bst and a var sum. Check if bst has pair whose sum should be equal to given sum

Time : O(n)
Space : O(n)
*/

#include<iostream>
#include<algorithm>
#include<unordered_set>
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

bool findPairInBST(Node *root, int sum, unordered_set<int> &s)
{
    if(root == NULL)
        return false;
    if(findPairInBST(root->left, sum, s) == true)
        return true;
    if(s.find(sum-root->key)!=s.end()) 
        return true;
    else
        s.insert(root->key);
    return findPairInBST(root->right, sum, s);
}

int main(){
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->right->left = new Node(16);
    root->right->right = new Node(40);
    int sum = 22;
    unordered_set<int> s;
    cout<<findPairInBST(root, sum, s);
    return 0;
}