#include <bits/stdc++.h>
using namespace std;

int bs(vector<int> arr, int target, int low, int high)
{
    if (low > high)
        return -1;

    int mid = low + (high - low) / 2;
    if (arr[mid] == target)
    {
        return mid;
    }
    else if (arr[mid] < target)
    {
        return bs(arr, target, mid + 1, high);
    }
    else
    {
        return bs(arr, target, low, mid - 1);
    }
}

int bs2(vector<int> arr, int target)
{
    int low = 0;
    int high = arr.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {-300, -238, 400, 200, 220, -1000, 3423, 232, 786};
    sort(arr.begin(), arr.end());

    int res = bs(arr, 200, 0, arr.size() - 1);
    cout << "The Binary search resulted in " << res << endl;
}