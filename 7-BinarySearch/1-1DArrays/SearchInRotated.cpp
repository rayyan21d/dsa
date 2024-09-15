#include <bits/stdc++.h>
using namespace std;
/*


*/

int bs(vector<int> &nums, int target)
{
    int n = nums.size();
    int low = 0, high = n - 1;
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target)
        {
            ans = mid;
            break;
        }
        else if (nums[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}

int search_brute(vector<int> &nums, int target)
{
    int ans;
    int n = nums.size();

    if (n == 0)
        return -1;
    // sorted not rotated
    if (nums[n - 1] >= nums[0])
    {

        ans = bs(nums, target);
    }
    else
    {
        // array is rotated
        int k;
        // find pivot
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i + 1] < nums[i])
            {
                k = i;
            }
        }
        // Sort the array
        sort(nums.begin(), nums.end());

        ans = bs(nums, target);
        if (ans != -1)
        {
            ans = (ans + k + 1) % n;
        }
    }

    return ans;
}

int search_optimal(vector<int> &nums, int target)
{

    int n = nums.size(), low = 0, high = n - 1;

    while (low <= high)
    {

        int mid = low + (high - low) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }

        // Left half is sorted
        if (mid >= low)
        {

            // Is the element between the sorted part?
            if (nums[low] <= target && target < nums[mid])
            {
                // If yes then search the sorted parh
                high = mid - 1;
            }
            else
            {
                // If no then eliminate the sorted part
                low = mid + 1;
            }
        }
        else
        { // Right half is sorted

            if (nums[mid] <= target && target < nums[high])
            {
                // If yes then search the sorted parh
                low = mid + 1;
            }
            else
            {
                // If no then eliminate the sorted part
                high = mid - 1;
            }
        }
    }

    return -1;
}

int search_optimal_duplicates(vector<int> &nums, int target)
{
    int n = nums.size(), low = 0, high = n - 1;

    while (low <= high)
    {

        int mid = low + (high - low) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }

        if (nums[mid] == nums[low] && nums[mid] == nums[high])
        {
            high--;
            low++;
        }

        if (mid >= low)
        { // Left half is sorted

            // Is the element between the sorted part?
            if (nums[low] <= target && target < nums[mid])
            {
                // If yes then search the sorted parh
                high = mid - 1;
            }
            else
            {
                // If no then eliminate the sorted part
                low = mid + 1;
            }
        }
        else
        { // Right half is sorted

            if (nums[mid] <= target && target < nums[high])
            {
                // If yes then search the sorted parh
                low = mid + 1;
            }
            else
            {
                // If no then eliminate the sorted part
                high = mid - 1;
            }
        }
    }

    return -1;
}

int main()
{
    vector<int> nums;
    int target, res;

    // All elements are distinct
    nums = {4, 5, 6, 7, 0, 1, 2};
    target = 0;
    res = search_optimal(nums, target);
    cout << "The search has returned: " << res << endl;

    // Duplicates Allowed
    nums = {2, 5, 6, 0, 0, 1, 2};
    target = 3;
    res = search_optimal_duplicates(nums, target);
    cout << "The search has returned: " << res << endl;
}