/* Starting from left character which atleast repeat two times. Print its index
Question is not based on character which is repeating first starting from left we have to check every character

I/p : "abbcc"
O/p : 1(index of b)

I/p : "abcd"
O/p : -1


************** Time=O(length), Space=O(CHAR)***************
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int CHAR = 256;
int checkRepetition(string &str)
{
    int count[CHAR] = {0};
    for (int i = 0; i < str.length(); i++)
        count[str[i]]++;
    for (int i = 0; i < str.length(); i++)
        if (count[str[i]] > 1)
            return i;
    return -1;
}

int main()
{
    string str = "adbc";
    cout<<checkRepetition(str);
    return 0;
}



// *************** Time = O(length + CHAR) *******************
#include<iostream>
#include<limits.h>
#include<string>
#include<algorithm>
using namespace std;

const int CHAR=256;
int checkRepetition(string &str)
{
    int fIndex[CHAR] = {0};
    fill(fIndex, fIndex+CHAR, -1);
    int res = INT_MAX;
    for(int i=0; i<str.length(); i++)
    {
        if(fIndex[str[i]]==-1)
        fIndex[str[i]] = i;
        else
        res = min(res, fIndex[str[i]]);
    }
    return (res==INT_MAX ? -1 : res);
}

int main(){
    string str = "adbbc";
    cout<<checkRepetition(str);
    return 0;
}
*/
// ****************** Most efficient solution***********************
// Time = O(length) space = O(CHAR)
#include<iostream>
#include<algorithm>
using namespace std;
const int CHAR = 256;
int checkRepetition(string &str)
{
    int res = -1;
    int *visited = new int[CHAR];
    fill(visited, visited+CHAR, false); 
    // mark all array elements as false then traverse from right side of string if value at array[str[i]] is false mark it as true and if value is true it means it have been visited before then update res. At last we will get minimized result automatically because we are traversing from right side
    for(int i=str.length()-1; i>=0; i--)
    {
        if(visited[str[i]])
        res = i;
        else
        visited[str[i]] = true;
    }
    return res;
}

int main(){
    string str = "adbbc";
    cout<<checkRepetition(str);
    return 0;
}