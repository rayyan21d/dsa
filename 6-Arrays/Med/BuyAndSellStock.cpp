/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and
choosing a different day in the future to sell thatstock.

Return the maximum profit you can achieve from this transaction.
If you cannot achieve any profit, return 0.


Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.


Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
*/

#include <bits/stdc++.h>
using namespace std;

// Brute force approach: Find the difference between each pair of elements
// Time complexity: O(n^2)
// Space complexity: O(1)
int maxProfit_brute_force(vector<int> &prices)
{
    int n = prices.size() - 1;
    int maxProfit = 0;

    for (int i = n; i >= 0; i--)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            int diff = prices[i] - prices[j];
            maxProfit = max(diff, maxProfit);
        }
    }

    return maxProfit;
}

int maxProfit_optimal(vector<int> &prices)
{
    int n = prices.size();
    int maxProfit = 0;
    int min = prices[0];

    for (int i = 0; i < n; i++)
    {
        if (prices[i] > min)
        {
            maxProfit = max(prices[i] - min, maxProfit);
        }
        else
        {
            min = prices[i];
        }
    }

    return maxProfit;
}

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << maxProfit_brute_force(prices) << endl;
    return 0;
}