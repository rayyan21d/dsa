/*

74. Search in a 2D Matrix
Link: https://leetcode.com/problems/search-a-2d-matrix/description/

*/

#include <bits/stdc++.h>
using namespace std;

bool bs(vector<int> &arr, int target)
{
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == target)
        {
            return true;
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

    return false;
}

bool searchMatrix(vector<vector<int>> &matrix, int target)
{

    int m = matrix.size();
    int n = matrix[0].size();

    int lowR = 0;
    int highR = m - 1;

    while ((lowR <= highR))
    {

        int midR = (lowR + highR) / 2;
        if ((matrix[midR][0] <= target) && (target <= matrix[midR][n - 1]))
        {
            return bs(matrix[midR], target);
        }
        else if (matrix[midR][0] < target)
        {
            lowR = midR + 1;
        }
        else
        {
            highR = midR - 1;
        }
    }

    return false;
}

bool searchMatrix_flatten(vector<vector<int>> &matrix, int target)
{
    // Flatten the matrix virtually and then apply binary search
    // Time complexity: O(log(m*n))
    // Space complexity: O(1)

    int m = matrix.size();
    int n = matrix[0].size();

    int low = 0;
    int high = m * n - 1;

    while (low <= high)
    {

        int mid = (low + high) / 2;
        int row = mid / n;
        int col = mid % n;
        int midElement = matrix[row][col];

        if (midElement == target)
        {
            return true;
        }
        else if (midElement < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return false;
}
int main()
{

    vector<vector<int>> matrix = {{1, 3, 5, 7},
                                  {10, 11, 16, 20},
                                  {23, 30, 34, 60}};

    int target = 34;

    cout << "Element is found: " << searchMatrix_flatten(matrix, target) << endl;
}