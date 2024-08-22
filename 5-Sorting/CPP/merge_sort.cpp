#include "mysort.h"

int main()
{
    int n = 10;
    int array[n];

    array_init(array, 10);

    merge_sort(array, 0, 9);
}

void merge(int *arr, int low, int mid, int high)
{

    // Maintain a temporary array
    int temp[high - low + 1];

    // Initialize the pointers
    int i = low;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= high)
    {

        if (arr[i] < arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }

    while (j <= high)
    {
        temp[k++] = arr[j++];
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }

    return;
};

void merge_sort(int *arr, int low, int high)
{
    if (low >= high)
        return;
    int mid = (low + high) / 2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid + 1, high);

    merge(arr, low, mid, high);
    print_array(arr, 10);
}

void print_merge_sorting_array(int *arr, int n, int i)
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
