/*
Given an integer array nums, find the
subarray with the largest sum, and return its sum.



Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
Example 2:

Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.


*/

#include <bits/stdc++.h>
using namespace std;

// Brute force approach
// Time complexity: O(n^3)
// Space complexity: O(1)
int maxSubArray_brute_force(vector<int> &nums)
{
    int n = nums.size();
    int max_sum = INT_MIN;
    for (int i = 0; i < n; i++)
    {

        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += nums[k];
            }
            max_sum = max(max_sum, sum);
        }
    }
    return max_sum;
}

// Brute force approach2
// Time complexity: O(n^2)
// Space complexity: O(1)
int maxSubArray_brute_force2(vector<int> &nums)
{
    int maxSum = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i; j < nums.size(); j++)
        {
            maxSum = max(accumulate(nums.begin() + i, nums.begin() + j + 1, 0), maxSum);
        }
    }

    return maxSum;
}

// Better approach
// Time complexity: O(n^2)
// Space complexity: O(1)
int maxSubArray_better(vector<int> &nums)
{
    int n = nums.size();
    int max_sum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += nums[j];
            max_sum = max(max_sum, sum);
        }
    }
    return max_sum;
}

// Optimal approach using Kadane's algorithm
// Time complexity: O(n)
// Space complexity: O(1)

int maxSubArray_optimal(vector<int> &nums)
{
    int maxSum = INT_MIN;
    int sum = 0;
    for (auto it : nums)
    {
        sum += it;
        maxSum = max(sum, maxSum);
        if (sum < 0)
            sum = 0;
    }

    return maxSum;
}