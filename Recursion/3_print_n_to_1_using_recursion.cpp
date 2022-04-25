// Write a recursion program to print numbers n to 1
/*
I/p : 5
O/p : 5, 4, 3, 2, 1
*/

#include<iostream>
using namespace std;

void fun(int n){
    if (n==0)
    return;
    cout<<n;
    cout<<" ";
    fun(n-1);
}

int main(){
    int n;
    cout<<"Enter value of n"<<endl;
    cin>>n;
    fun(n);
    return 0;
}

// Time complexity = theta(n)
// Auxillary space = O(n)