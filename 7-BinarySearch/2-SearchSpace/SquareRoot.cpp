/*

*/

#include <bits/stdc++.h>
using namespace std;

int sqrt(int n)
{

    if (n < 0)
        return -1;
    if (n == 0 || n == 1)
        return n;

    int low = 1, high = n;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (mid * mid == n)
            return mid;

        else if (mid * mid > n)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
}

int main()
{
    int n = 20;
    int sq_root;

    sq_root = sqrt(n);

    cout << sq_root << endl;
}
