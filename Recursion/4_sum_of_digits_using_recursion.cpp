// Write a recursive function to find sum of digits using recursion

#include<iostream>
using namespace std;

int sumOfDigits(int n){
    if(n==0)
    return 0;
    return(n%10 + sumOfDigits(n/10));
}

int main(){
    int n;
    cin>>n;
    cout<<sumOfDigits(n);
    return 0;
}