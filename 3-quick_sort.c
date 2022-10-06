#include "sort.h"

/**
 * swap_int_array - swap elements in an int array
 *
 * @array: The array containing items to be swapped
 * @i: The source index
 * @j: The destination index
 * @size: The array size
 */
void swap_int_array(int *array, size_t i, size_t j, size_t size)
{
	int temp;

	if (array[i] != array[j])
	{
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
		print_array(array, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 *
 * @array: The array to be sorted
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	quick_sort_r(array, 0, size - 1, size);
}

/**
 * lomuto_partition - partitions an array using lomuto partitioning
 * algorithm
 *
 * @array: The array been sorted
 * @low: The lower bound of the array
 * @high: The higher bound of the array
 * @size: The array size
 * Return: (size_t) The pivot
 */
size_t lomuto_partition(int *array, size_t low, size_t high, size_t size)
{
	int pivot = 0;
	size_t i = 0, j = 0;

	pivot = array[high];
	i = low - 1;
	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i += 1;
			swap_int_array(array, i, j, size);
		}
	}
	i += 1;
	swap_int_array(array, i, high, size);
	return (i);
}

/**
 * quick_sort_r - Performs a quick sort recursively
 *
 * @array: The array to be sorted
 * @low: The lower bound
 * @high: The higher bound
 * @size: The array size
 */
void quick_sort_r(int *array, long low, long high, size_t size)
{
	size_t partition;

	if (low >= high || low < 0)
		return;

	partition = lomuto_partition(array, low, high, size);
	/* sorting the 2 partitions */
	quick_sort_r(array, low, partition - 1, size);
	quick_sort_r(array, partition + 1, high, size);
}
