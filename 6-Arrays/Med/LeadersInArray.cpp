#include <bits/stdc++.h>
using namespace std;
/*

Given an array, print all the elements which are leaders.
A Leader is an element that is greater than all of the elements on its right side in the array.

Example 1:

Input:
arr = [4, 7, 1, 0]
Output:
7 1 0
Explanation:
Rightmost element is always a leader. 7 and 1 are greater than the elements in their right side.


Example 2:
Input:
arr = [10, 22, 12, 3, 0, 6]
Output:
22 12 6

Explanation:
6 is a leader.
In addition to that, 12 is greater than all the elements in its right side (3, 0, 6),
also 22 is greater than 12, 3, 0, 6.


*/

// Brute Force Solution
// Time Complexity: O(n^2)
// Space Complexity: O(1)
// Approach: For each element, check if it is greater than all the elements on its right side.

vector<int> leaders_brute_force(vector<int> arr)
{
    int n = arr.size();
    vector<int> result;
    for (int i = 0; i < n; i++)
    {

        bool leader = true;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[i])
            {
                leader = false;
                break;
            }
        }

        if (leader)
        {
            result.push_back(arr[i]);
        }
    }

    return result;
}

// Optimal Solution
// Time Complexity: O(n)
// Space Complexity: O(1)
// Approach : Maintain a variable max which stores the maximum element from the right side.
//            Traverse the array from right to left and if the current element is greater than max, then it is a leader.
vector<int> leaders_optimal(vector<int> arr)
{

    int max = INT_MIN;
    vector<int> result;
    int n = arr.size();
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            result.push_back(arr[i]);
        }
    }

    return result;
}

void print(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

int main()
{

    // Initialize the array
    vector<int> result;
    vector<int> arr = {4, 7, 1, 0};

    print(arr);
    result = leaders_optimal(arr);

    print(result);
}