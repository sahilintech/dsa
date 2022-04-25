// Given a value x find square root of x . If no. is not a perfect square , find its floor square root
// Time = O(log n)

#include<iostream>
#include<algorithm>
using namespace std;

int squareRoot(int x)
{
    int low = 1, high = x;
    int res;
    while(low<=high)
    {
        int mid = (low+high)/2;
        int midSq = mid*mid; 
        if(midSq == x)
            return mid;
        else if(midSq > x)
            high = mid -1;
        else
        {
            low = mid+1;
            res = mid;
        }
    }
    return res;
}

int main(){
    int x;
    cin>>x;
    int val = squareRoot(x);
    cout<<val;
    return 0;
}