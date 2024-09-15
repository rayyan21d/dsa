/*

Given a sorted array of N integers and an integer x, write a program to find the lower bound of x.

Leetcode: https://leetcode.com/problems/search-insert-position/description/

Example 1:
Input Format:
 N = 4, arr[] = {1,2,2,3}, x = 2
Result:
 1
Explanation:
 Index 1 is the smallest index such that arr[1] >= x.

Example 2:
Input Format:
 N = 5, arr[] = {3,5,8,15,19}, x = 9
Result:
 3
Explanation:
 Index 3 is the smallest index such that arr[3] >= x.

*/

#include <bits/stdc++.h>
using namespace std;

int lb(vector<int> arr, int target, int low, int high, int answer)
{
    if (low > high)
        return answer;

    int mid = low + (high - low) / 2;
    if (arr[mid] >= target)
    {
        // Eliminate the right subspace
        answer = mid;
        return lb(arr, target, low, mid - 1, answer);
    }
    else
    {
        // Eliminate the left subspace
        return lb(arr, target, mid + 1, high, answer);
    }
}

int lb_non_recursive(vector<int> arr, int target)
{
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    int ans = n;

    while (low <= high)
    {
        int mid = (high + low) / 2;
        if (arr[mid] >= target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    return ans;
}

int ub_non_recursive(vector<int> arr, int target)
{

    int n = arr.size();
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] > target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    return ans;
}

int main()
{
    vector<int> arr = {3, 5, 8, 15, 19};
    int x = 9;
    int n = arr.size();

    cout << lb_non_recursive(arr, x) << endl;

    // Using STL
    cout << lower_bound(arr.begin(), arr.end(), x) - arr.begin() << endl;
}