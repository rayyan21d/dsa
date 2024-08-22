/*

https://leetcode.com/problems/move-zeroes/

Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.



Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]

*/

#include <bits/stdc++.h>
using namespace std;

// Copy all nonzeros to a new array and then copy all zeros to the end of the array
// Time Complexity: O(n)
// Space Complexity: O(n)
void moveZeroes_brute_force(vector<int> &nums)
{
    vector<int> cp(nums.begin(), nums.end());

    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
        {
            count++;
        }
    }

    for (int i = 0, j = 0; i < cp.size(); i++)
    {
        if (cp[i] != 0)
        {
            nums[j] = cp[i];
            j++;
        }
    }

    for (int i = cp.size() - count; i < cp.size(); i++)
    {
        nums[i] = 0;
    }
}

// Follow a two pointer approach
// First find the first zero, if not found return if found set j= index;
// i will simply start from j+1 and if nums[i] is not zero then swap nums[i] with nums[j]
// Time Complexity: O(n)
// Space Complexity: O(1)
void moveZeroes_optimal(vector<int> &nums)
{
    int j = -1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0 && j == -1)
        {
            j = i;
            break;
        }
    }
    if (j == -1)
        return;
    for (int i = j + 1; i < nums.size(); i++)
    {
        if (nums[i] != 0)
        {
            swap(nums[i], nums[j]);
            j++;
        }
    }
}