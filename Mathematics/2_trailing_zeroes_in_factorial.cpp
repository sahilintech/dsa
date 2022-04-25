#include<iostream>
using namespace std;

int countTrailingZeroes(int n)
{
    int res = 0;
    for(int i=5; i<=n; i=i*5)
    {
        res = res + (n/i);
    }
    cout<<res;
}
int main(){
    int n;
    cin>>n;
    countTrailingZeroes(n);
    return 0;
}