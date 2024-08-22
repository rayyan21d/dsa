/*

Given an array nums containing n distinct numbers in the range [0, n],
return the only number in the range that is missing from the array.



Example 1:
Input: nums = [3,0,1]
Output: 2
Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3].
    2 is the missing number in the range since it does not appear in nums.


Example 2:
Input: nums = [0,1]
Output: 2
Explanation: n = 2 since there are 2 numbers, so all numbers are in the range [0,2].
    2 is the missing number in the range since it does not appear in nums.


Example 3:

Input: nums = [9,6,4,2,3,5,7,0,1]
Output: 8
Explanation: n = 9 since there are 9 numbers, so all numbers are in the range [0,9].
    8 is the missing number in the range since it does not appear in nums.

*/

#include <bits/stdc++.h>
using namespace std;

// Approach-1 Calculating the sum of n natural numbers and then subtracting the sum of the array from it.
// T.C - O(n)
// S.C - O(1)
int missingNumber_brute_force(vector<int> &nums)
{
    int sum = 0;
    int n = nums.size();
    int arrSum = (n * (n + 1)) / 2;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
    }

    return arrSum - sum;
}

/*
Approach 2
In this approach, you use bitwise XOR operation to find the missing number.
XOR operation on a number with itself results in 0.
So, if you XOR all the numbers from 0 to n and all the numbers in the array, the result will be the missing number.

Initialize missing to 0.
Iterate over the array and XOR each number with missing.
After the iteration, the value in missing will be the missing number

*/

int missingNumber_xor(vector<int> &nums)
{
    int x = -1, y = -1;
    int n = nums.size();
    for (int i = 0; i <= n; i++)
    {
        x = x ^ i;
    }
    for (int i = 0; i < n; i++)
    {
        y = y ^ nums[i];
    }
    return x ^ y;
}