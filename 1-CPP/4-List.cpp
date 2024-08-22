#include <bits/stdc++.h>
using namespace std;

// List operations are way faster than vector operations
int main()
{
    list<int> listName;
    list<int> g1;

    for (int i = 1; i <= 5; i++)
        g1.push_back(i);

    cout << "Output of begin and end: ";
    for (auto i = g1.begin(); i != g1.end(); ++i)
        cout << *i << " ";

    // emplace_back

    // a container containing 5 instances of 10 is defined here:
    list<int> v(5, 10);

    // 5 instances of a garbage value is here...
    list<char> v1(5);

    // A vector which is similar to v1
    // list v2(v1);

    // Iterator points to the memory location of the first element of the vector
    list<int>::iterator it = v.begin();

    // The end will point right after the v1
    list<char>::iterator it2 = v1.end();

    // This is a way to loop through a vector, auto === vector<int>::iterator it
    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
}