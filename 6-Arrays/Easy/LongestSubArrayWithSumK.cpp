/*
Given an array arr containing n integers and an integer k.
Your task is to find the length of the longest Sub-Array with the sum of the elements equal to the given value k.

Input :
arr[] = {10, 5, 2, 7, 1, 9}, k = 15
Output : 4
Explanation:
The sub-array is {5, 2, 7, 1}.

Input :
arr[] = {-1, 2, 3}, k = 6
Output : 0
Explanation:
There is no such sub-array with sum 6.


Expected Time Complexity: O(n).
Expected Auxiliary Space: O(n).
*/

#include <bits/stdc++.h>
using namespace std;

// Approach 1: Brute force
// Generate all subarrays and check if sum is equal to k
// Time complexity: O(n^3) or O(n^2)
// Space complexity: O(1)
int longestSubArrayWithSumK_brute_force(vector<int> a, int k)
{
    int length = 0;
    for (int i = 0; i < a.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < a.size(); j++)
        {
            sum += a[j];
            if (sum == k)
            {
                length = max(length, j - i + 1);
            }
        }
    }

    return length;
}

// Approach 2: Using Hashing
// Hash the sum of subarrays and check if sum-k is present in hash
// If a sum is already present in hash, then it means that the subarray from that index to current index has sum equal to k
// Time complexity: O(n)
// Space complexity: O(n)
// int longestSubArrayWithSumK_better(vector<int> a, long long k)
// {
//     int length = 0;
//     int sum = 0;
//     unordered_map<int, int> mpp;

//     for (int i = 0; i < a.size(); i++)
//     {
//         sum += a[i];
//         mpp[sum] = i; // store the sum and its index

//         if (sum == k)
//         {
//             length = i + 1;
//         }

//         if (mpp.find(sum - k) != mpp.end())
//         {
//             int len = mpp[sum - k];
//             length = max(length, i - len);
//         }
//     }
// }

//
// int longestSubArrayWithSumK_optimal(vector<int> a, long long k)
// {
// }

int main()
{
    vector<int> a = {1, 2, 1, 2, 1};
    long long k = 3;
    cout << longestSubArrayWithSumK_brute_force(a, k) << endl;

    return 0;
}