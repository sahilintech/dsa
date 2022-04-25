/*
Given a matrix as input print matrix as pattern of snake i.e 1st row as it is, then start 2nd row from last element, 3rd row as it is, then start 4th row from last element...
I/p : 1 2 3 4
      5 6 7 8
      9 10 11 12
      13 14 15 16
O/p : 1, 2, 3, 5, 8, 7, 6, 5, 9, 10, 11, 12, 16, 15, 14, 13
Time: 0(row*col);
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void snakePattern(vector<vector<int>> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (i % 2 != 0)
        {
            for (int j = v[i].size() - 1; j >= 0; j--)
                cout << v[i][j] << " ";
        }
        else
        {
            for (int j = 0; j < v[i].size(); j++)
                cout << v[i][j] << " ";
        }
    }
}

int main()
{
    vector<vector<int>> v{{1, 2, 3, 4},
                          {5, 6, 7, 8},
                          {9, 10, 11, 12},
                          {13, 14, 15, 16}};
    snakePattern(v);
    return 0;
}