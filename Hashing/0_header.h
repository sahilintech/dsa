#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int longestLength(int arr[], int n, int sum)
{
    unordered_map<int, int> m;
    int prefixSum = 0, length = 0;
    for (int i = 0; i < n; i++)
    {
        prefixSum += arr[i];
        if (prefixSum == sum) // handle condition like arr[] = {5, 4, 3} , sum = 9 , this case will not be handled by below conditions
            length = i + 1;
        if (m.find(prefixSum) == m.end()) // If presum is already present in map we do not want to insert it again and update its value because it will have higher index if we find this presum as presum - sum in next iteration then it will have higher index which will not give us longest subarray
            m.insert({prefixSum, i});
        if (m.find(prefixSum - sum) != m.end()) // if we find prefixsum - sum in hash we find max length by doing curr index - index of previous presum which is stored as value in hash
        {
            auto it = m.find(prefixSum - sum);
            length = max(length, i - (it->second));
        }
    }
    return length;
}