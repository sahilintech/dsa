// Unordered set is implementing using hasing. All operatios on unordered set works on 0(1)

#include<iostream>
#include<unordered_set>
#include<algorithm>
using namespace std;
int main(){
    unordered_set <int> s;
    s.insert(15);
    s.insert(20);
    s.insert(25);
    s.insert(30);
    s.insert(40);
    for(auto it=s.begin(); it!=s.end(); it++) // iterate over unordered set
    cout<<*it<<" "<<endl;
    cout<<s.size()<<endl; // returns size of unordered set
    s.clear(); // clear the unordered set
    cout<<s.size()<<endl; // now size will be zero after clearing unordered set
    s.insert(15);
    s.insert(20);
    s.insert(25);
    s.insert(30);
    s.insert(40);
    cout<<s.size()<<endl;
    if(s.find(15)==s.end()) // if s.find(15) return iterator equal to after the last element of unordered set it means element is not present in it
    cout<<"NOT FOUND\n";
    else
    cout<<"FOUND\n"<<*(s.find(15))<<endl; // *(s.find(15)) will print 15 because s.find(15) returns address of 15 element
    if(s.count(15)) // since count can return only 0 and 1 because unordered set cannot have same elements present so if(1) return true
    cout<<"FOUND\n";
    else
    cout<<"NOT FOUND\n";
    s.erase(15);
    cout<<s.size()<<endl;
    auto it = s.find(25);
    s.erase(it); // erases 25 because it will contain address of 25 element
    cout<<s.size()<<endl;
    s.erase(s.begin(), s.end()); // Erases whole unordered set
    cout<<s.size()<<endl;
    return 0;
}