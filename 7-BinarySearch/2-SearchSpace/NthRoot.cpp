/*

*/

#include <bits/stdc++.h>
using namespace std;

int n_rt(int n, int m)
{

    if (n < 0)
        return -999;
    if (n == 0 || n == 1)
        return n;

    int low = 1, high = n;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int pow = 1;
        for (int i = 1; i <= m; i++)
        {
            pow *= mid;
        }

        if (pow == n)
            return mid;

        else if (pow > n)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return -1;
}

int main()
{
    int n = 9;
    int sq_root;

    sq_root = n_rt(n, 3);

    cout << sq_root << endl;
}
