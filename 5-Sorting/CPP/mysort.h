#ifndef MY_HEADER
#define MY_HEADER

#define underline "\033[4m"
#include <bits/stdc++.h>
using namespace std;
#include <random>

void array_init(int *arr, int n);
void print_array(int *arr, int n);

void print_array(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void array_init(int *arr, int n)
{

    random_device rd;
    uniform_int_distribution<int> dist(1, 200);
    for (int i = 0; i < n; i++)
    {
        arr[i] = dist(rd);
    }

    cout << "Array initialized: ";
    print_array(arr, n);

    return;
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    return;
}

void print_sorting_array(int *arr, int n, int i)
{
    for (int k = 0; k < n; k++)
    {
        if (k == i)
        {
            cout << underline << arr[k] << "\033[24m" << " ";
        }
        else
        {
            cout << arr[k] << " ";
        }
    }
    cout << endl;
}

void selection_sort(int *arr, int n);
void bubble_sort(int *arr, int n);
void insertion_sort(int *arr, int n);
void merge_sort(int *arr, int low, int high);
void quick_sort(int *arr, int low, int high);
void heap_sort(int *arr, int n);

#endif