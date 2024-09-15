/*

73. Set Matrix Zeroes

Given a m x n matrix, if an element is 0, set its entire row and column to 0.
Do it in-place.


Example 1:
Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
Example 2:

*/

#include <bits/stdc++.h>
using namespace std;

// Time: O(m*n), Space: O(m+n)
// Approach: Create a copy of the matrix and iterate over the original matrix.
// If we find a zero, set the entire row and column to zero in the copy matrix.
// Finally, copy the copy matrix to the original matrix.

void setZeroes_brute1(vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<vector<int>> copy = matrix;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == 0)
            {
                for (int k = 0; k < rows; k++)
                {
                    copy[k][j] = 0;
                }

                for (int k = 0; k < cols; k++)
                {
                    copy[i][k] = 0;
                }
            }
        }
    }

    matrix = copy;
}

// This brute force does not use an additional space
// Time Complexity: O(m*n*(m+n)), Space Complexity: O(1)

void setZeroes_brute2(vector<vector<int>> &matrix)
{

    // Marking the rows and columns to be set to zero
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == 0)
            {
                for (int k = 0; k < rows; k++)
                {
                    if (matrix[k][j] != 0)
                        matrix[k][j] = -1;
                }

                for (int k = 0; k < cols; k++)
                {
                    if (matrix[i][k] != 0)
                        matrix[i][k] = -1;
                }
            }
        }
    }

    // Setting the rows and columns to zero
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == -1)
            {
                matrix[i][j] = 0;
            }
        }
    }

    return;
}

// Time: O(m*n), Space: O(m+n)
// Approach: Create two vectors to store the rows and columns that need to be set to zero.
// This uses an additional space of O(m+n) which needs to be optimized.
void setZeroes_better(vector<vector<int>> &matrix)
{

    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<int> row(rows, 1);
    vector<int> col(cols, 1);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == 0)
            {
                row[i] = 0;
                col[j] = 0;
            }
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (row[i] == 0 || col[j] == 0)
            {
                matrix[i][j] = 0;
            }
        }
    }
}

void setZeroes_optimal(vector<vector<int>> &matrix)
{
}

void printMatrix(vector<vector<int>> &matrix)
{
    cout << "Matrix: " << endl;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};

    printMatrix(matrix);

    setZeroes(matrix);

    printMatrix(matrix);
    return 0;
}