#include "mysort.h"

int main()
{
	int n = 10;
	int array[n];

	array_init(array, 10);

	selection_sort(array, 10);
}

void selection_sort(int *arr, int n)
{
	cout << "Selection Sort:\n";

	int min;

	for (int i = 0; i < n - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[min])
			{
				min = j;
			}
		}

		if (min != i)
		{
			swap(&arr[i], &arr[min]);
		}
		cout << "After " << i << "th iteration: ";
		print_sorting_array(arr, n, i);
	}
}
