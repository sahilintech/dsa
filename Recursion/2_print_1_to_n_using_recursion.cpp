// Write a recursion program to print numbers n to 1
/*
I/p : 5, 4, 3, 2, 1
O/p : 5
*/

#include<iostream>
using namespace std;

void fun(int n){
    if(n==0)
    return;
    fun(n-1);
    cout<<n;
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
