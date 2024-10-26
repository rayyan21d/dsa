/*

1552. Magnetic Force Between Two Balls
Link: https://leetcode.com/problems/magnetic-force-between-two-balls/

In the universe Earth C-137,
Rick discovered a special form of magnetic force between two balls if they are put in his new invented basket.
Rick has n empty baskets, the ith basket is at position[i],
Morty has m balls and needs to distribute the balls into the baskets such that
the minimum magnetic force between any two balls is maximum.

Rick stated that magnetic force between two different balls at positions x and y is |x - y|.


Given the integer array position and the integer m. Return the required force.

Example 1:

Input: position = [1,2,3,4,7], m = 3
Output: 3
Explanation: Distributing the 3 balls into baskets 1, 4 and 7 will make the magnetic force between ball pairs [3, 3, 6].
The minimum magnetic force is 3. We cannot achieve a larger minimum magnetic force than 3.

Example 2:

Input: position = [5,4,3,2,1,1000000000], m = 2
Output: 999999999
Explanation: We can use baskets 1 and 1000000000.

*/

#include <bits/stdc++.h>
using namespace std;

bool placeBalls(vector<int> &position, int m, int minDistance)
{
    // We place the first cow in the first position
    int placed = 1;
    int lastPlaced = position[0];
    bool ans;
    int n = position.size();

    for (int i = 1; i < n; i++)
    {

        if (position[i] - lastPlaced >= minDistance)
        {
            placed++;
            lastPlaced = position[i];
        }
    }

    if (placed >= m)
    {
        ans = true;
    }
    else
    {
        ans = false;
    }

    return ans;
}

// Brute force
// Time complexity: O(n^2)
// Approach: To find the maximum distance between two points
// we start by placing two balls at a dist. of atleast 1, then we check if all balls can be placed
// Then we check for minDist=2,3... until the first time we can't place the balls.
int maxDistance_brute(vector<int> &position, int m)
{

    int n = position.size();
    sort(position.begin(), position.end());
    int ans = -1;

    for (int dist = 1; dist <= position[n - 1] - position[0]; dist++)
    {

        if (placeBalls(position, m, dist))
        {
            continue;
        }
        else
        {
            ans = dist - 1;
            break;
        }
    }

    return ans;
}

// Optimal Solution
// Time complexity: O(nlogn)
// Approach: We use binary search to find the maximum distance between two points
// We start by placing two balls at a dist. of atleast 1, then we check if all balls can be placed
int maxDistance(vector<int> &position, int m)
{

    int n = position.size();
    sort(position.begin(), position.end());

    int low = 1; // For optimized solution: minOf(positions)
    int high = position[n - 1] - position[0];
    int ans = -1;

    while (low <= high)
    {

        int midDist = low + (high - low) / 2;

        if (placeBalls(position, m, midDist))
        {
            ans = midDist;
            low = midDist + 1;
        }
        else
        {
            high = midDist - 1;
        }
    }

    return ans;
}

void printSolution(vector<int> &position, int m)
{
    cout << "Position of balls: ";
    for (int i = 0; i < position.size(); i++)
    {
        cout << position[i] << " ";
    }
    cout << endl;
    cout << "The minimum of maximum magnetic force for placing " << m << " balls is: " << maxDistance(position, m) << endl
         << endl;
}

int main()
{

    vector<int> position = {0, 3, 4, 7, 10, 9};
    int m = 4;

    printSolution(position, m);

    position = {5, 4, 3, 2, 1, 1000000000};
    m = 2;
    printSolution(position, m);
}
