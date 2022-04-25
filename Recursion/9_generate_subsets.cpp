// Given a string print all subsets of it
// I/p = "AB"
// O/p = "", "A", "B", "AB"

#include <iostream>
#include <string>
using namespace std;

void subsets(string &str, string curr = "", int i = 0)
{
    if (i == str.length()) // length of string is 3;
    {
        cout << curr << endl;
        return;
    }
    subsets(str, curr, i + 1);
    subsets(str, curr + str[i], i + 1);

}

int main()
{
    string str;
    getline(cin, str);
    subsets(str);
    return 0;
}