// Print all permutations of given string
/* 
I/P : "ABC"
O/P : ABC, ACB, BAC, BCA, CBA, CAB
*/

#include<iostream>
#include<string>
using namespace std;

void permute(string &s, int i=0){
    if(i==s.length()-1)
    {
        cout<<s<<" ";
        return;
    }
    for(int j=i; j<s.length(); j++)
    {
        swap(s[i], s[j]);
        permute(s, i+1);
        swap(s[i], s[j]);
    }
}

int main(){
    string s;
    cout<<"Enter string"<<endl;
    getline(cin, s);
    cout<<s.length();
    permute(s);
    return 0;
}