#include <bits/stdc++.h>
using namespace std;

long long xPowN(int x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    return x * xPowN(x, n - 1);
}

int main()
{
    cout << xPowN(8, -3) << endl;
}