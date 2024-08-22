#include "mysort.h"

void bubble_sort(int *arr, int n)
{
    cout << "Bubble Sort:\n";
    for (int i = 0; i < n; i++)
    {
        int swapped = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                swapped++;
            }
        }
        if (swapped == 0)
        {
            break;
        }

        cout << "After " << i << "th iteration: ";
        print_sorting_array(arr, n, n - i - 1);
    }
}

int main()
{
    int n = 10;
    int array[n];

    array_init(array, 10);

    bubble_sort(array, 10);
}