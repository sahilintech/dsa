#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int fact (n);
    int res = 1;
    for(int i=2; i<=n; i++)
    {
        res = res*i;
    }
    cout<<res;
    return 0;
}