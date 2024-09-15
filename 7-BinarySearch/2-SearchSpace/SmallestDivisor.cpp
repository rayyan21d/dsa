/*


*/
#include <bits/stdc++.h>
using namespace std;

int maxOf(vector<int> &nums)
{

    int max = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > max)
        {
            max = nums[i];
        }
    }

    return max;
}

int smallestDivisor(vector<int> &nums, int threshold)
{

    int n = nums.size();
    int low = 1;
    int high = maxOf(nums);
    int ans = -1;

    while (low <= high)
    {

        int mid = (high + low) / 2;

        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            // Be EXTRA Careful of ciel & double
            sum = sum + ceil((double)(nums[i]) / (double)(mid));
        }

        if (sum <= threshold)
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

    vector<int> nums;
    int threshold;

    nums = {1, 2, 5, 9};
    threshold = 6;
    // Expected Output: 5
    cout << "Test 1:" << smallestDivisor(nums, threshold) << endl;

    nums = {44, 22, 33, 11, 1};
    threshold = 5;
    // Expected Output: 44
    cout << "Test 2:" << smallestDivisor(nums, threshold) << endl;
}
