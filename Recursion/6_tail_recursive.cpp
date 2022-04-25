// Tail recursive of finding factorial

#include <iostream>
using namespace std;

int fact(int n, int k=1){
    if(n==0 || n==1)
    return k;
    return fact(n-1, k*n);
}

int main()
{
    int n;
    cout << "Enter value of n" << endl;
    cin >> n;
    cout<<fact(n);
    return 0;
}