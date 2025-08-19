#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick sort
 * @array: Pointer to the array to be sorted
 * @size: Number of elements in the array
 *
 * Return: Void function
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}

	quick_sort_recursive(array, size, 0, size - 1);
}

/**
 * quick_sort_recursive - Recursively sorts subarrays using quick sort
 * @array: Pointer to the array to be sorted
 * @size: Total size of the original array (for printing)
 * @low: Starting index of the subarray
 * @high: Ending index of the subarray
 *
 * Return: Void function
 */

void quick_sort_recursive(int *array, size_t size, int low, int high)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = lomuto_partition(array, size, low, high);

		quick_sort_recursive(array, size, low, pivot_index - 1);

		quick_sort_recursive(array, size, pivot_index + 1, high);
	}
}

/**
 * lomuto_partition - Partitions array using Lomuto partition scheme
 * @array: Pointer to the array to be partitioned
 * @size: Total size of the original array (for printing)
 * @low: Starting index of the partition
 * @high: Ending index of the partition (pivot element)
 *
 * Return: Final position of the pivot element
 */

int lomuto_partition(int *array, size_t size, int low, int high)
{
	int pivot = array[high];
	int i = low - 1;
	int j, tmp, temp;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i = i + 1;

			if (i != j)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;

				print_array(array, size);
			}
		}
	}

	if (array[i + 1] != array[high])
	{
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;

		print_array(array, size);
	}

	return (i + 1);
}
