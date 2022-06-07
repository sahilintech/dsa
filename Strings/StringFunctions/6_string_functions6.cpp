// Function == find,replace
#include<iostream>
#include<string>
using namespace std;
int main(){
    string str="There are multiple objects in this data with objects.";
    string str1="object";
    size_t position_count = str.find(str1);
    if(position_count!=string::npos)
    {
        cout<<"First object found at: "<<position_count<<endl;
    }

    position_count=str.find("objects are small",position_count+1,6);// here i am telling function to find from 20th position and find first six character of string given
    if(position_count!=string::npos)
    {
        cout<<"Second object found at: "<<position_count<<endl;
    }

    position_count=str.find("data");
    if(position_count!=string::npos)
    {
        cout<<"Data also found at: "<<position_count<<endl;
    }

    position_count=str.find(".");
    if(position_count!=string::npos)
    {
        cout<<"\".\" also found at: "<<position_count<<endl;
    }

    // replace()
    str.replace(str.find(str1),str1.length(),"classes"); //It will find str1 in str i.e object and second argument i am saying to give length to be replaced by class
    cout<<str<<endl;
    return 0;
}