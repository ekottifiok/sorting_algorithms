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
 * quick_sort_hoare - Sorts an array using the hoare
 * partition algorithm
 *
 * @array: The array to be sorted
 * @size: The array size
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;

	quick_sort_hoare_r(array, 0, size - 1, size);
}

/**
 * quick_sort_hoare_r - Recursively sorts an array using the hoare
 * partition algorithm
 *
 * @array: The array to be sorted
 * @low: The lower bound
 * @high: The higher bound
 * @size: The array size
 */
void quick_sort_hoare_r(int *array, long low, long high, size_t size)
{
	long partition;

	if (low < high)
	{
		partition = hoare_partition(array, low, high, size);
		quick_sort_hoare_r(array, low, partition, size);
		quick_sort_hoare_r(array, partition + 1, high, size);
	}
}

/**
 * hoare_partition - partitions an array using hoare partition
 * algorithm
 *
 * @array: The array been sorted
 * @low: The lower bound of the array
 * @high: The higher bound of the array
 * @size: The array size
 * Return: (long) The pivot
 */
long hoare_partition(int *array, long low, long high, size_t size)
{
	int pivot = 0;
	size_t i = 0, j = 0;

	pivot = array[high];
	/* left index */
	i = low - 1;
	/* right index */
	j = high + 1;

	while (1) /* infinite loop */
	{
		do
		{ /* move the left index at least once */
			i = i + 1;
		} while (array[i] < pivot);

		do
		{ /* move the right index at least once */
			j = j - 1;
		} while (array[j] > pivot);

		/* If the indices cross then return */
		if (i >= j)
		{
			if ((int)j == high)
				return (j - 1);
			return (j);
		}

		/* swap elements */
		swap_int_array(array, i, j, size);
	}
}
