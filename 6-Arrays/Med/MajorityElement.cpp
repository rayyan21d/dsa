
/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times.
You may assume that the majority element always exists in the array.



Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    int n = nums.size();
}

// Approach 1: Brute Force
// Space Complexity: O(1)
// Time Complexity: O(n^2)
void majority_element_brute_force(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (nums[i] == nums[j])
            {
                count++;
            }
        }
        if (count > n / 2)
        {
            cout << nums[i] << endl;
            return;
        }
    }
    cout << -1 << endl;
}

// Approach 2: Using Hash Map
// Space Complexity: O(n)
// Time Complexity: O(n)
void majority_element_better(vector<int> &nums)
{
    int n = nums.size();
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[nums[i]]++;
        if (mp[nums[i]] > n / 2)
        {
            cout << nums[i] << endl;
            return;
        }
    }
    cout << -1 << endl;
}

// Space Complexity: O(1)
// Time Complexity: O(n)
// Boyer-Moore Voting Algorithm
void majority_element_optimal(vector<int> &nums)
{
    int n = nums.size();
    int count = 0;
    int element = 0;
    for (int i = 0; i < n; i++)
    {
        if (count == 0)
        {
            element = nums[i];
            count++;
        }
        if (nums[i] == element)
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    cout << element << endl;
}