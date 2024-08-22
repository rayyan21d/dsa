#include <bits/stdc++.h>
using namespace std;

int main()
{

    // Pair utility class
    pair<int, char> p = make_pair(2, 'b');
    cout << p.first << " " << p.second << endl;

    pair<int, int> p2(1, 2);

    pair<int, int> p3(3, 4);

    // swaps the content if they are of same type
    p2.swap(p3);

    cout << "After swap: " << p2.first << " " << p3.first << endl;
}