#include "sort.h"

/**
 * swap_int_array - swap elements in an int array
 *
 * @array: The array containing items to be swapped
 * @i: The source index
 * @j: The destination index
 * @size: The array size
 */
void swap_int_array(int *array, size_t i, size_t j, size_t size __attribute__((unused)))
{
	int temp;

	if (array[i] != array[j])
	{
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	}
}

/**
 * print_sorted - print sorted array
 *
 * @array: The sorted array
 * @n: The length to be printed
 */
void print_sorted(int *array, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
	{
		if (i != 0)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}

/**
 * bitonic_merge - recursively sorts a bitonic sequence
 *
 * @array: Array to be sorted
 * @low: Lower bound
 * @n: nth size to be sorted
 * @asc: ascending or decending
 * @size: Array size
 */
void bitonic_merge(int *array, int low, int n, int asc, size_t size)
{
	int k, i, j;
	char *dir = asc > 0 ? "UP" : "DOWN";

	if (n > 1)
	{
		k = n / 2;

		for (i = low; i < low + k; i++)
		{
			j = i + k;
			if (asc == (array[i] > array[j]))
			{
				swap_int_array(array, i, j, 0);
				printf("Result [%d/%ld] (%s):\n", n, size, dir);
				print_sorted(array, n);
			}
			bitonic_merge(array, low, k, asc, size);
			bitonic_merge(array, low + k, k, asc, size);
		}
	}
}

/**
 * bitonic_sort - sorts an array using bitonic algorithm
 *
 * @array: The array to be sorted
 * @low: The lower bound
 * @n: The nth pos
 * @asc: Whether ascending (UP) or decending (DOWN)
 * @size: Array size
 */
void bitonic_sort_r(int *array, int low, int n, int asc, size_t size)
{
	char *dir = asc > 0 ? "UP" : "DOWN";

	if (n > 1)
	{
		int k = n / 2;

		printf("Merging [%d/%ld] (%s):\n", n, size, dir);
		print_sorted(array, n);
		bitonic_sort_r(array, low, k, 1, size);
		bitonic_sort_r(array, low + k, k, 0, size);

		print_sorted(array, n);
	}
}

/**
 * bitonic_sort - sorts an array of integers in ascending order
 * using the Bitonic sort algorithm
 *
 * @array: The array to be sorted
 * @size: The size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	bitonic_sort_r(array, 0, size, 1, size);
}
