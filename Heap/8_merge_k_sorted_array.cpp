/*
Given a vector of vectors which are individually sorted. Merge them into a single array whose all elements are sorted

I/p : [{5,10}, {4,9}, {6}]
O/p : {4, 5, 6, 9, 10}

Time: O(nk lognk)
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct Triplet
{
    int val, aPos, vPos;
    Triplet(int v, int ap, int vp)
    {
        val = v;
        aPos = ap;
        vPos = vp;
    }
};

struct myComp
{
    bool operator()(Triplet &a, Triplet &b)
    {
        return a.val > b.val;
    }
};

vector<int> mergeKSortedArray(vector<vector<int>> arr)
{
    vector<int> res;
    priority_queue<Triplet, vector<Triplet>, myComp> pq;
    for (int i = 0; i < arr.size(); i++)
    {
        Triplet t(arr[i][0], i, 0);
        pq.push(t);
    }
    while (pq.empty() == false)
    {
        Triplet curr = pq.top();
        pq.pop();
        res.push_back(curr.val);
        int ap = curr.aPos;
        int vp = curr.vPos;
        if (vp + 1 < arr[ap].size())
        {
            Triplet t(arr[ap][vp + 1], ap, vp + 1);
            pq.push(t);
        }
    }
    return res;
}

int main()
{
    vector<vector<int>> arr = {{10, 20, 30}, {5, 15}, {1, 9, 11, 18}};
    vector<int> res = mergeKSortedArray(arr);
    for (auto i : res)
        cout << i << " ";
    return 0;
}