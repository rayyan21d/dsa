#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<int> vectorName;
    vector<int> g1;

    for (int i = 1; i <= 5; i++)
        g1.push_back(i);

    cout << "Output of begin and end: ";
    for (auto i = g1.begin(); i != g1.end(); ++i)
        cout << *i << " ";

    // emplace_back

    // a container containing 5 instances of 10 is defined here:
    vector<int> v(5, 10);

    // 5 instances of a garbage value is here...
    vector<char> v1(5);

    // A vector which is similar to v1
    vector<char> v2(v1);

    // Iterator points to the memory location of the first element of the vector
    vector<int>::iterator it = v.begin();

    // The end will point right after the v1
    vector<char>::iterator it2 = v1.end();

    // This is a way to loop through a vector, auto === vector<int>::iterator it
    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }

    vectorOperations();
}

void vectorOperations()
{

    vector<int> v;
    v.push_back(1);
    v.push_back(2);

    // v = {1, 2}

    // Iterator

    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }

    // Inserting element in a vector
    v.insert(v.begin(), 5);

    // Erasing element from a vector
    v.erase(v.begin());

    // pop_back() returns the last element
}
