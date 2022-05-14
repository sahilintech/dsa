// Starting from left character which does not appear more than one time
/*
I/p : "aabbcc"
O/p : -1

I/p : "abcd"
O/p : 0 (index of a)



// ******** Efficient solution *************

Time : O(length) , Space O(CHAR) two traverals

#include <iostream>
#include <algorithm>
using namespace std;
const int CHAR = 256;
int checkNonRepetition(string &str)
{
    // create a count array with all indexes marked as zero then increase indexes with respect to char of string , then if count[str[i]]==1 return index
    int count[CHAR] = {0};
    for (int i = 0; i < str.length(); i++)
        count[str[i]]++;
    for (int i = 0; i < str.length(); i++)
        if (count[str[i]] == 1)
            return i;
    return -1;
}

int main()
{
    string str = "aacc";
    cout << checkNonRepetition(str);
    return 0;
}
*/
//  ************* Most efficient solution if string is larger than traversal of char can be generalised as constant , thus it does only one traversal 
// Time and space are same as previous. this solution is efficient for continous streams of characters
#include <iostream>
#include <algorithm>
#include <climits>
#include <string>
using namespace std;
const int CHAR = 256;
int checkNonRepetition(string &str)
{
    int firstIndex[CHAR];
    fill(firstIndex, firstIndex+CHAR, -1); // filling array elements as -1
    int res = INT_MAX;
    for (int i = 0; i < str.length(); i++)
    {
        if (firstIndex[str[i]] == -1)  
            firstIndex[str[i]] = i; // every f[str[i]] will be filled with its index for first time
        else
            firstIndex[str[i]] = -2; // if element repeats more than 1 time it will not have -1 and will be filled with -2
    }
    for (int i = 0; i < CHAR; i++)
        if (firstIndex[i] >= 0)
            res = min(res, firstIndex[i]); // mimimize result for elements which are containing index greater than equal to zero , repeated elements will contain -2
    return (res == INT_MAX ? -1 : res);
}

int main()
{
    string str = "abacc";
    cout << checkNonRepetition(str);
    return 0;
}
