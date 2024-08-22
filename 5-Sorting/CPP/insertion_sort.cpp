#include "mysort.h"

int main()
{
    int n = 10;
    int array[n];

    array_init(array, 10);

    insertion_sort(array, 10);
}

void insertion_sort(int *arr, int n)
{
    cout << "Insertion Sort:\n";
    for (int i = 0; i < n; i++)
    {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            swap(&arr[j], &arr[j - 1]);
            j--;
        }

        cout << "After " << i << "th iteration: ";
        print_sorting_array(arr, n, i);
    }
}
