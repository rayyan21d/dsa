#include "mysort.h"

int main()
{
    int n = 10;
    int array[n];

    array_init(array, 10);

    cout << "Quick sort: \n";
    quick_sort(array, 0, 9);
}

int partition(int *arr, int low, int high)
{
    // Try different pivots
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j)
    {

        while (arr[i] <= pivot && i < high)
        {
            i++;
        }
        while (arr[j] > pivot && j > low)
        {
            j--;
        }

        if (i < j)
        {
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[low], &arr[j]);
    return j;
}
void quick_sort(int *arr, int low, int high)
{
    if (low >= high)
        return;
    int pivot = partition(arr, low, high);
    print_array(arr, 10);

    quick_sort(arr, low, pivot - 1);
    quick_sort(arr, pivot + 1, high);
}
