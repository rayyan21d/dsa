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

int minDiff(vector<int> &position)
{
    int min = INT_MAX;

    for (int i = 0; i < position.size() - 1; i++)
    {
        int distance = position[i + 1] - position[i];

        if (distance < min)
        {
            min = distance;
        }
    }

    return min;
}

int maxDistance_brute(vector<int> &position, int m)
{

    return 0;
}

void printSolution(vector<int> &position, int m)
{
    cout << "Position of balls: ";
    for (int i = 0; i < position.size(); i++)
    {
        cout << position[i] << " ";
    }
    cout << endl;
    cout << "The minimum of maximum magnetic force for placing" << m << " balls is: " << maxDistance_brute(position, m) << endl;
}

int main()
{

    vector<int> position = {1, 2, 8, 4, 9};
    int m = 3;

    printSolution(position, m);
}
