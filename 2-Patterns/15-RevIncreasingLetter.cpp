#include <bits/stdc++.h>
using namespace std;
void nLetterTriangle(int n)
{

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i + 1; j++)
        {
            cout << char(64 + j) << ' ';
        }
        cout << endl;
    }
}
