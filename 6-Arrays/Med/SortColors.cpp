
/*


*/

#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}

void sortColors_better(vector<int> &nums)
{
    int zero = 0, one = 0, two = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
        {
            zero++;
        }

        if (nums[i] == 1)
        {
            one++;
        }
        else
        {
            two++;
        }
    }

    for (int i = 0; i < zero; i++)
    {
        nums[i] = 0;
    }
    for (int i = zero; i < zero + one; i++)
    {
        nums[i] = 1;
    }
    for (int i = zero + one; i < nums.size(); i++)
    {
        nums[i] = 2;
    }
}

void sortColors_optimal(vector<int> &nums)
{
    int low = 0, mid = 0, high = nums.size() - 1;

    while (mid <= high)
    {
        if (nums[mid] == 0)
        {
            swap(nums[low], nums[mid]);
            mid++;
            low++;
        }
        else if (nums[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

int main()
{
    vector<int> nums = {1, 1, 1, 0, 0, 2, 1, 0};
    cout << "Before Sorting: ";
    print(nums);
    sortColors_optimal(nums);
    cout << "After Sorting: ";
    print(nums);
}