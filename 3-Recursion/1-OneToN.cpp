#include <bits/stdc++.h>
using namespace std;

void recursiveFunction(int x, vector<int> &arr)
{
    // Write Your Code Here
    if (x == 0)
    {
        return;
    }

    recursiveFunction(x - 1, arr);
    arr.emplace_back(x);
}

vector<int> printNos(int x)
{
    // Declaring empty integer array
    vector<int> ans;

    // Calling recursive function
    recursiveFunction(x, ans);

    return ans;
}

// Another approach is

vector<int> returnArray(int x)
{

    if (x == 0)
    {
        return;
    }

    vector<int> arr = returnArray(x - 1);
    arr.emplace_back(x);
    return arr;
}
