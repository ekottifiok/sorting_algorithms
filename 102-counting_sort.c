#include "sort.h"

/**
 * get_max - Returns the maximum number
 *
 * @array: The array to be tranversed
 * @size: The array size
 *
 * Return: (int) the largest value in the array
 */
int get_max(int *array, size_t size)
{
	size_t i;
	int max = array[0];

	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * counting_sort - sorts an array of integers in ascending order using
 * the Counting sort algorithm
 *
 * @array: The array to be sorted
 * @size: The array size
 */
void counting_sort(int *array, size_t size)
{
	int *count;
	int *output;
	int max;
	long i;

	if (array == NULL || size <= 1)
		return;
	max = get_max(array, size);
	count = malloc(sizeof(int) * (max + 1));
	output = malloc(sizeof(int) * (size + 1));
	if (output == NULL || count == NULL)
		return;

	for (i = 0; i < max; i++)
		count[i] = 0;

	/* store count for each element */
	for (i = 0; i < (long)size; i++)
		count[array[i]]++;

	/* find cummulative frequency */
	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];

	print_array(count, max + 1);

	/* find index of each element in input and place in output */
	for (i = size - 1; i >= 0; i--)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}

	/* store sorted elements in the array */
	for (i = 0; i < (long)size; i++)
		array[i] = output[i];
	free(count);
	free(output);
}
