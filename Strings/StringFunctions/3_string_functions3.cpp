// Functions == begin,end,rbegin,rend
#include<iostream>
#include<string>
using namespace std;
int main(){
    string str = "learnandgrow";
    string::iterator it;
    string::reverse_iterator it1;
    cout<<"The string using forward iterator is :";
    for(it=str.begin(); it!=str.end(); it++)
    {
        cout<<*it;
    }
    cout<<endl;
    cout<<"The string using reverse iterator is: ";
    for(it1=str.rbegin(); it1!=str.rend(); it1++)
    {
        cout<<*it1;
    }
    return 0;
}