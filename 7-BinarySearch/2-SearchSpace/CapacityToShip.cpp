/*

1011. Capacity To Ship Packages Within D Days
Link: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days

A conveyor belt has packages that must be shipped from one port to another within days days.

The ith package on the conveyor belt has a weight of weights[i].
Each day, we load the ship with packages on the conveyor belt (in the order given by weights).
We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in
all the packages on the conveyor belt being shipped within days days.


Example 1:

Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
Output: 15
Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
1st day: 1, 2, 3, 4, 5
2nd day: 6, 7
3rd day: 8
4th day: 9
5th day: 10

Note that the cargo must be shipped in the order given, so using a ship of capacity 14 and splitting the packages into parts like (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed.


Example 2:

Input: weights = [3,2,2,4,1,4], days = 3
Output: 6
Explanation: A ship capacity of 6 is the minimum to ship all the packages in 3 days like this:
1st day: 3, 2
2nd day: 2, 4
3rd day: 1, 4


Example 3:

Input: weights = [1,2,3,1,1], days = 4
Output: 3
Explanation:
1st day: 1
2nd day: 2
3rd day: 3
4th day: 1, 1

*/

#include <bits/stdc++.h>
using namespace std;

int CalculateDays(vector<int> &weights, int capacity)
{

    int weight = 0;
    int days = 1;
    int n = weights.size();
    for (int i = 0; i < n; i++)
    {

        if (weight + weights[i] > capacity)
        {
            days++;
            weight = weights[i];
        }
        else
        {
            weight += weights[i];
        }
    }

    return days;
}

int sumOf(vector<int> &arr)
{
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
    }
    return sum;
}

int maxOf(vector<int> &arr)
{
    int max = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }

    return max;
}

int shipWithinDays(vector<int> &weights, int days)
{

    int low = maxOf(weights);
    int high = sumOf(weights);
    int ans, daysTaken;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        daysTaken = CalculateDays(weights, mid);

        if (daysTaken <= days)
        {
            high = mid - 1;
            ans = mid;
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}

int main()
{

    vector<int> weights;
    int days;

    weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    days = 5;
    // Expected Output: 15
    cout << "Test 1:" << "" << endl;

    weights = {3, 2, 2, 4, 1, 4};
    days = 3;
    // Expected Output: 6
    cout << "Test 2:" << "" << endl;
}