// String functions== find, rfind, find_first_of, find_last_of
#include<iostream>
#include<string>
using namespace std;
int main(){
    string str="learn and learn very fast";
    
    cout<<"First occurence of \"Learn\" starts from: ";
    cout<<str.find("learn")<<endl; // this will find learn and prints position from where it starts

    cout<<"First occurence of character from \"trn\" is at: ";
    cout<<str.find_first_of("trn")<<endl; // this will find position of any one character mentioned from first

    cout<<"Last occurence of character from \"n\" is at: ";
    cout<<str.find_last_of("n")<<endl; // this will find position of any one character mentioned from last

    cout<<"Last occurence of \"Learn\" starts from: ";
    cout<<str.rfind("learn")<<endl; // this will find learn and prints position from where it starts but last learn it wiil see
    return 0;
}