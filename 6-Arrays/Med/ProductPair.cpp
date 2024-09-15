#include <bits/stdc++.h>
using namespace std;

/*
Given an array, arr[] of distinct elements, and a number x,
find if there is a pair in arr[] with a product equal to x.
Return true if there exists such pair otherwise false.


Input: arr[] = [10, 20, 9, 40], x = 400
Output: true
Explanation: As 10 * 40 = 400, the answer is true.

Input: arr[] = [-10, 20, 9, -40], x = 30
Output: false
Explanation: No pair exists with product 30.

*/

// Better approach
// Time complexity: O(n)
// Space complexity: O(n)
// Approach: Using Hashing and Map.
// Traverse the array and store the index of each element in a map.
// For each element, check if x is divisible by the element.
// If it is divisible, then check if the complement of the element is present in the map.
// If it is present, then return true.
// Otherwise, return false.

// The time complexity of storing and searching in a map is O(1).
bool product_pair_better(vector<int> &arr, int x)
{
    unordered_map<int, int> mpp;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]] = i;
    }

    for (int i = 0; i < n; i++)
    {

        if (x % arr[i] == 0)
        {
            int comp = x / arr[i];
            if (mpp.find(comp) != mpp.end() && mpp[comp] != i)
            {
                cout << "Pair found at index " << i << " and " << mpp[comp] << endl;
                return true;
            }
        }
    }

    return false;
}

// Optimal Approach
// Time complexity: O(n)
// Space complexity: O(n)
// Approach: Using Set
// Traverse the array and store the elements in a set.
// For each element, check if x is divisible by the element.
// If it is divisible, then check if the complement of the element is present in the set.
// If it is present, then return true.
// Otherwise, return false.
bool product_pair_optimal(vector<int> &arr, int x)
{

    sort(arr.begin(), arr.end());
    int n = arr.size();
    for (int i = 0, j = n - 1; i < j;)
    {
        int prod = arr[i] * arr[j];
        if (prod == x)
        {
            cout << "Pair found at index " << i << " and " << j << endl;
            return true;
        }
        else if (prod < x)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
}

int main()
{
    vector<int> arr = {10, 20, 9, 40, 30, 50, 40};
    int x = 400;

    bool pair = product_pair_optimal(arr, x);

    if (pair)
    {
        cout << "Pair exists" << endl;
    }
    else
    {
        cout << "Pair does not exist" << endl;
    }
}