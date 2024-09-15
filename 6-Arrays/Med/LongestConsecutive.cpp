#include <bits/stdc++.h>
using namespace std;

/*

Leetcode 128: Longest Consecutive Sequence

Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
You must write an algorithm that runs in O(n) time.

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
Therefore its length is 4.


Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9


*/

// Approach: Brute Force
// Time Complexity: O(n^2)
// Space Complexity: O(1)
// The brute force approach is to iterate over the array and for each element,
// check if the next element is present in the array.
// If it is present, increment the count and continue checking for the next element.
// If the next element is not present, update the longest sequence length if the current count is greater than the longest sequence length.
// Return the longest sequence length at the end.

bool find(vector<int> &nums, int x)
{
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == x)
        {
            return true;
        }
    }

    return false;
}

int longest_consecutive_brute_force(vector<int> &nums)
{
    int count;
    int longest = 1;
    int n = nums.size();

    if (n == 0)
    {
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        int x = nums[i];
        count = 1;
        while (find(nums, x + 1) == true)
        {
            count++;
            x++;
        }

        longest = max(longest, count);
    }

    return longest;
}

// Approach: Better
// Time Complexity: O(nlogn)
// Space Complexity: O(1)
// The better approach is to sort the array and then iterate over the array.
// For each element, check if the next element is equal to the current element + 1.
// If it is, increment the count and continue checking for the next element.
// If the next element is not equal to the current element + 1,
// update the longest sequence length if the current count is greater than the longest sequence length.
// Return the longest sequence length at the end.
// Disadvantage: It modifies the original array or requires an additional array to store the sorted array.
int longest_consecutive_better(vector<int> &nums)
{

    vector<int> arr = nums;
    int n = arr.size();
    if (n == 0)
    {
        return 0;
    }

    sort(arr.begin(), arr.end());
    int count = 0;
    int longest = 1;
    int lastSmaller = INT_MIN;

    for (int i = 0; i < n; i++)
    {

        if (arr[i] - 1 == lastSmaller)
        {
            count++;
            lastSmaller = arr[i];
        }
        else if (lastSmaller != arr[i])
        {
            count = 1;
            lastSmaller = arr[i];
        }

        longest = max(longest, count);
    }

    return longest;
}

// Approach: Optimal
// Time Complexity: O(n)
// Space Complexity: O(n)
// The optimal approach is to use a hash set to store all the elements of the array.
// It does not modify the original array.
// Time: 1170ms (Leetcode)
int longest_consecutive_optimial(vector<int> &nums)
{

    unordered_set<int> s;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        s.insert(nums[i]);
    }

    int longest = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (s.find(nums[i] - 1) == s.end())
        {

            count = 1;
            int k = 1;
            while (s.find(nums[i] + k) != s.end())
            {
                count++;
                k++;
            }

            longest = max(count, longest);
        }
    }

    return longest;
}

int main()
{

    vector<int> nums = {100, 4, 200, 2};
    vector<int> sorted = {-1, -1, 0, 1, 3, 4, 5, 6, 7, 8, 9};

    int cons = longest_consecutive_better(nums);

    cout << "The length of the longest consecutive elements sequence is: " << cons << endl;
}