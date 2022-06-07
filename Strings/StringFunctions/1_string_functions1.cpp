// Functions of string == getline,pushback,popback
#include<iostream>
#include<string>
using namespace std;
int main(){
    string str;
    cout<<"Enter the string"<<endl;

    //getline()
    getline(cin,str,'s'); // 's' is delimiter here upto what you want to print 
    // Note it will not print s
    cout<<"The initial string is:"<<endl;
    cout<<str<<endl;

    //push_back()
    str.push_back('s'); // will add s to last
    cout<<"The string after push back is:"<<endl;
    cout<<str<<endl;

    // pop_back()
    str.pop_back(); // it removes last character
    cout<<str;
    return 0;
}