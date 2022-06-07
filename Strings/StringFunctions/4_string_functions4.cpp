// Functions == copy,swap,compare
#include<iostream>
using namespace std;
int main(){
    string str1 = "learn grow and explore";
    string str2 = "learn grow";
    char arr[14];

    //copy()
    str1.copy(arr,13,0); // copies first 13 characters of string to array starting from 0
    cout<< "The new copied character array is: ";
    cout<<arr<<endl;

    // swap()
    cout<<"The 1st string before swapping is:";
    cout<<str1<<endl;
    cout<<"The 2nd string before swapping is:";
    cout<<str2<<endl;
    str1.swap(str2);
    cout<<"The 1st string after swapping is:";
    cout<<str1<<endl;
    cout<<"The 2nd string after swapping is:";
    cout<<str2<<endl;

    //compare
    string str3="hellot";
    string str4="hellotre";
    cout<<str3.compare(str4); // returns 0 if equal else not equal then difference between characters
    return 0;
}