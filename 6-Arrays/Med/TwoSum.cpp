
/*


*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
}

// Space Complexity: O(1)
// Time Complexity: O(n^2)
pair<int, int> two_sum_brute_force(vector<int> &nums, int target)
{
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] + nums[j] == target)
            {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

// Space Complexity: O(n)
// Time Complexity: O(n)
pair<int, int> two_sum_better(vector<int> &nums, int target)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        if (mp.find(target - nums[i]) != mp.end())
        {
            return {mp[target - nums[i]], i};
        }
        mp[nums[i]] = i;
    }
    return {-1, -1};
}

// Space Complexity: O(1) or O(n) if we consider the space used by the output array
// Time Complexity: O(n) + O(nlogn)sorting = O(nlogn)
pair<int, int> two_sum_optimal(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    for (int i = 0, j = nums.size() - 1; i < j;)
    {
        int sum = nums[i] + nums[j];

        if (sum < target)
        {
            i++;
        }

        if (sum > target)
        {
            j--;
        }

        if (sum == target)
        {
            return {i, j};
        }
    }

    return {-1, -1};
}