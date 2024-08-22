/*

You are given a 0-indexed integer array nums of even length
consisting of an equal number of positive and negative integers.
You should return the array of nums such that the the array follows the given conditions:

Every consecutive pair of integers have opposite signs.
For all integers with the same sign, the order in which they were present in nums is preserved.
The rearranged array begins with a positive integer.
Return the modified array after rearranging the elements to satisfy the aforementioned conditions.


Example 1:
Input: nums = [3,1,-2,-5,2,-4]
Output: [3,-2,1,-5,2,-4]
Explanation:
The positive integers in nums are [3,1,2]. The negative integers are [-2,-5,-4].
The only possible way to rearrange them such that they satisfy all conditions is [3,-2,1,-5,2,-4].


Example 2:
Input: nums = [-1,1]
Output: [1,-1]
Explanation:
1 is the only positive integer and -1 the only negative integer in nums.
So nums is rearranged to [1,-1].

*/

#include <bits/stdc++.h>
using namespace std;

vector<int> Rearrange(vector<int> &nums)
{
    vector<int> pos, neg;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        if (nums[i] >= 0)
        {
            pos.push_back(nums[i]);
        }
        else
        {
            neg.push_back(nums[i]);
        }
    }

    for (int i = 0; i < n / 2; i++)
    {
        nums[2 * i] = pos[i];
        nums[2 * i + 1] = neg[i];
    }

    return nums;
}

int main()
{
}