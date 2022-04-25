// Given an array containing stock prices of n different days . We need to buy and sell the stock such that profit is maximized.
/*
I/p: {1, 5, 3, 8, 12}
> Buy the stock at first day and sell it on 2nd day the profit will be 5-1 = 4.
> Again buy the stock at 3rd day and sell it on 5th day the profit will be 12-3 = 9.

O/p : 9+4 = 13
*/

#include <iostream>
using namespace std;

void maxProfit(int price[], int n)
{
    int profit = 0;
    for (int i = 1; i < n; i++)
    {
        if (price[i] > price[i - 1])
            profit += price[i] - price[i-1]; // Sum up all profits 
    }
    cout<<profit;
}

int main()
{
    int price[] = {1, 5, 3, 8, 12};
    int n = sizeof(price) / sizeof(price[0]);
    maxProfit(price, n);
    return 0;
}