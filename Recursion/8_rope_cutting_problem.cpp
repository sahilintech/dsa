// Given a length of rope. Find the max. no. of pieces you can cut into it with given length.
// I/p : n=5, a=2, b=5, c=1
// O/p : 5
// Make 5 pieces of 1 length each.

// I/p : n=23, a=11, b=9, c=12 
// O/p : Make two piece of length 11 and 12

// Note = If not possible return -1 i.e if given cutting legths are greater than rope length


#include<iostream>
#include<algorithm>
using namespace std;

int maxPieces(int n, int a, int b, int c){
    if(n==0)
    return 0;
    if(n<0)
    return -1;
    int tempRes = max(maxPieces(n-a, a, b, c), maxPieces(n-b, a, b, c));
    int res = max(tempRes, maxPieces(n-c, a, b, c));
    if(res==-1)
    return -1;
    return res+1; // will return max + 1 (i.e 0+1)
    
}

int main(){
    int n, a, b, c;
    cin>>n>>a>>b>>c;
    cout<<maxPieces(n, a, b, c);
    return 0;
}