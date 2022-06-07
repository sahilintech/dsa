// Functions of string == capacity,resize,length,shrinktofit,empty
#include<iostream>
#include<string>
using namespace std;
int main(){
    string str = "learn and grow and learn fast";
    cout<<"The initial string is:"<<endl;
    cout<<str<<endl;

    // resize()
    str.resize(2); // resizes string to first 2 characters
    cout<<"The string after resize operation is:"<<endl;
    cout<<str<<endl;

    // capacity()
    cout<<"The capacity of string is: ";
    cout<<str.capacity()<<endl;

    // length()
    cout<<"The length of string is: ";
    cout<<str.length()<<endl;

    // shrink_to_fit
    str.shrink_to_fit();
    cout<< "The new capacity after shrinking is: ";
    cout<<str.capacity();
    return 0;
}