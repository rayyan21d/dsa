/*

1539. Kth Missing Positive Number

Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.

Return the kth positive integer that is missing from this array.


Example 1:

Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...].
The 5th missing positive integer is 9.

Example 2:

Input: arr = [1,2,3,4], k = 2
Output: 6
Explanation: The missing positive integers are [5,6,7,...].
The 2nd missing positive integer is 6.


*/

#include <bits/stdc++.h>
using namespace std;

// Brute Force
// Time Complexity: O(n)
// Space Complexity: O(n)
// We create a sequence of numbers and search linearly
// We can optimize this by using binary search
void kth_missing_brute(vector<int> arr, int k)
{

    // Since the array is sorted, we create a sequence and search linearly
    vector<int> vec;
    int n = arr.size();
    int max = arr[n - 1];

    int count = 0;
    for (int i = 1; i < max; i++)
    {
        if (arr[count] != i)
        {
            vec.push_back(i);
        }
        else
        {
            count++;
        }
    }

    cout << "The Kth missing element is: " << vec[k - 1] << endl;
}

// Binary Search Approach
// Time Complexity: O(logn)
// Space Complexity: O(1)
void kth_missing(vector<int> arr, int k)
{
    int n = arr.size();
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] - (mid + 1) < k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    cout
        << "The Kth missing element is: " << low + k << endl;
}

int main()
{

    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;

    kth_missing_brute(arr, k);

    kth_missing(arr, k);
}
