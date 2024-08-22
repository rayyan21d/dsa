#include <bits/stdc++.h>
using namespace std;

int main()
{
    queue<int> q;

    q.push(1);
    q.push(3);
    q.push(8);

    cout << q.front() << endl;

    cout << q.back() << endl;
}

void priority()
{
    priority_queue<int> pq;

    pq.push(5);
    pq.push(2);
    pq.push(9);

    cout << pq.top() << endl;

    priority_queue<int, vector<int>, greater<int>> pq2;
}