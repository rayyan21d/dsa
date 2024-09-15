#include <bits/stdc++.h>
using namespace std;
/*


*/

int rotated_min_optimal(vector<int> &nums)
{
    int n = nums.size();
    int low = 0, high = n - 1;
    int min = INT_MAX;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] < min)
        {
            min = nums[mid];
        }

        // Left half is sorted
        if (nums[mid] >= nums[low])
        {
            if (min > nums[low])
                min = nums[low];

            // Discard the sorted part
            low = mid + 1;
        }
        else
        {
            // Right half is sorted
            if (nums[mid] < min)
                min = nums[mid];

            // Discard the sorted part
            high = mid - 1;
        }
    }

    return min;
}

int main()
{
    vector<int> arr;
    int min;

    arr = {4, 5, 6, 7, 0, 1, 2};
    min = rotated_min_optimal(arr);

    cout << "The Least element is: " << min << endl;
}