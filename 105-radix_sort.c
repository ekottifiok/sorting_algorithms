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
 * @place: Number of places
 */
void counting_sort(int *array, size_t size, int place)
{
	int *output;
	int count[10] = {0};
	long i;

	output = malloc(sizeof(int) * (size + 1));
	if (output == NULL)
		return;
	/* calculate the count of elements */
	for (i = 0; i < (long)size; i++)
	{
		count[(array[i] / place) % 10]++;
	}

	/* calculate the cumulative frequency*/
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	/* Place the elements */
	for (i = size - 1; i >= 0; i--)
	{
		output[count[(array[i] / place) % 10] - 1] = array[i];
		count[(array[i] / place) % 10]--;
	}

	for (i = 0; i < (long)size; i++)
	{
		array[i] = output[i];
	}
	free(output);
}

/**
 * radix_sort - sorts an array of integers in ascending order
 * using the Radix sort algorithm
 *
 * @array: The array to be sorted
 * @size: The array size
 */
void radix_sort(int *array, size_t size)
{
	int max = get_max(array, size);
	int place = 1;

	for (place = 1; max / place > 0; place *= 10)
	{
		counting_sort(array, size, place);
		print_array(array, size);
	}
}
