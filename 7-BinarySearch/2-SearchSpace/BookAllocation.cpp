/*

Given an array ‘arr of integer numbers, ‘ar[i]’ represents the number of pages in the ‘i-th’ book.
There are a ‘m’ number of students, and the task is to allocate all the books to the students.

Allocate books in such a way that:

1-Each student gets at least one book.
2-Each book should be allocated to only one student.
3-Book allocation should be in a contiguous manner.

You have to allocate the book to ‘m’ students such that the maximum number of pages assigned to a student is minimum.
If the allocation of books is not possible. return -1

Example 1:
Input Format:
 n = 4, m = 2, arr[] = {12, 34, 67, 90}
Result:
 113
Explanation:
 The allocation of books will be 12, 34, 67 | 90. One student will get the first 3 books and the other will get the last one.

Example 2:
Input Format:
 n = 5, m = 4, arr[] = {25, 46, 28, 49, 24}
Result:
 71
Explanation: The allocation of books will be 25, 46 | 28 | 49 | 24.


We can allocate books in several ways but it is clearly said in the question that
we have to allocate the books in such a way that the maximum number of pages received by a student should be minimum.

Assume the given array is {25 46 28 49 24} and number of students, M = 4.
Now, we can allocate these books in different ways. Some of them are the following:

25 | 46 | 28 | 49, 24  → Maximum no. of pages a student receive = 73
25 | 46 | 28, 49 | 24  → Maximum no. of pages a student receive = 77
25 | 46, 28 | 49 | 24  → Maximum no. of pages a student receive = 74
25, 46 | 28 | 49 | 24  → Maximum no. of pages a student receive = 71
From the above allocations, we can clearly observe that the minimum possible maximum number of pages is 71.



*/

#include <bits/stdc++.h>
using namespace std;

bool placeBalls(vector<int> &position, int m, int minDistance)
{
}

// Brute force
int maxDistance_brute(vector<int> &position, int m)
{
}

// Optimal Solution
int maxDistance(vector<int> &position, int m)
{
}

void printSolution(vector<int> &position, int m)
{
}

int main()
{

    vector<int> arr = {12, 34, 67, 90};
    int m = 2;

    printSolution(arr, m);

    arr = {25, 46, 28, 49, 24};
    int m = 4;

    printSolution(arr, m);
}
