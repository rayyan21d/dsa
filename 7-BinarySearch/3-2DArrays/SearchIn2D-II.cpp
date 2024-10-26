/*

240. Search a 2D Matrix II
Link: https://leetcode.com/problems/search-a-2d-matrix-ii/

Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix.
This matrix has the following properties:
Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.

Example 1:


Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
Output: true
Example 2:


Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
Output: false

*/

#include <bits/stdc++.h>
using namespace std;

// Time complexity: O(m*log(n))
// Approach: For each row, we perform binary search to find the target element
// If found, we return the index of the element
// Else we return {-1,-1}

int bs(vector<int> &arr, int target)
{

    int low = 0;
    int high = arr.size() - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == target)
            return mid;

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

pair<int, int> searchMatrix(vector<vector<int>> &matrix, int target)
{

    int m = matrix.size();

    for (int i = 0; i < m; i++)
    {
        int ans = bs(matrix[i], target);

        if (ans != -1)
            return {i, ans};
    }

    return {-1, -1};
}

// Optimal Solution
// Time complexity: O(m+n)
// Approach: We start from the top right corner of the matrix
// If the element is greater than the target, we move left
// If the element is smaller than the target, we move down
// If the element is equal to the target, we return the index of the element
// If we reach the end of the matrix, we return {-1,-1}
pair<int, int> searchMatrix_optimal(vector<vector<int>> &matrix, int target)
{

    int m = matrix.size();
    int n = matrix[0].size();

    int row = 0;
    int col = n - 1;

    while ((row < m) && (col >= 0))
    {

        int mid = matrix[row][col];

        if (mid == target)
            return {row, col};
        else if (mid < target)
        {
            row++;
        }
        else
        {
            col--;
        }
    }

    return {-1, -1};
}

void printSolution(pair<int, int> ans)
{

    if (ans.first != -1)
        cout << "Element found at: " << ans.first << " " << ans.second << endl;
    else
        cout << "Element not found" << endl;
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}};

    int target = 5;

    pair<int, int> ans = searchMatrix_optimal(matrix, target);
    printSolution(ans);
}