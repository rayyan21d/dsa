/*




*/

#include <bits/stdc++.h>
using namespace std;

vector<int> merge(vector<int> &A, vector<int> &B)
{

    int a = A.size();
    int b = B.size();
    vector<int> ans;

    int i = 0, j = 0;

    while ((i < a) && (j < b))
    {

        if (A[i] <= B[j])
        {
            ans.push_back(A[i]);
            i++;
        }
        else
        {
            ans.push_back(B[j]);
            j++;
        }
    }

    while (i < a)
    {
        ans.push_back(A[i]);
        i++;
    }

    while (j < b)
    {
        ans.push_back(B[j]);
        j++;
    }

    return ans;
}

double findMedianSortedArrays_brute(vector<int> &nums1, vector<int> &nums2)
{

    vector<int> merged = merge(nums1, nums2);

    int n = merged.size();

    int mid = (n) / 2;

    if (n % 2 == 1)
    {
        return merged[mid];
    }

    return (merged[mid - 1] + merged[mid]) / 2.0;
}

double findMedianSortedArrays_better(vector<int> &nums1, vector<int> &nums2)
{
    int n1 = nums1.size();
    int n2 = nums2.size();
    int n = n1 + n2;

    int index2 = n / 2;
    int index1 = n / 2 - 1;

    // Merging w.o additional space
    int i = 0, j = 0;
    int k = 0;
    int el1 = -1;
    int el2 = -1;

    while ((i < n1) && (j < n2))
    {

        if (nums1[i] <= nums2[j])
        {
            if (k == index1)
                el1 = nums1[i];
            if (k == index2)
                el2 = nums1[i];
            i++;
            k++;
        }
        else
        {
            if (k == index1)
                el1 = nums2[j];
            if (k == index2)
                el2 = nums2[j];
            j++;
            k++;
        }
    }

    while (i < n1)
    {
        if (k == index1)
            el1 = nums1[i];
        if (k == index2)
            el2 = nums1[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        if (k == index1)
            el1 = nums2[j];
        if (k == index2)
            el2 = nums2[j];
        j++;
        k++;
    }

    if (n % 2 == 1)
    {
        return el2;
    }

    return (double)(double)(el1 + el2) / 2.0;
}

int main()
{
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};

    cout << findMedianSortedArrays_better(nums1, nums2) << endl;
}