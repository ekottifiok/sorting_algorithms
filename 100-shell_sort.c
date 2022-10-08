#include "sort.h"

/**
 * knuth_sequence - Generates a knuth sequence
 * @size: The size of the sequence
 *
 * Return: an array filled with knuth series
 */
int *knuth_sequence(size_t size)
{
	int *gaps;
	int n = 0;
	size_t i;

	gaps = malloc(sizeof(int) * (size / 3));

	for (i = 0; i < size / 3; i++)
	{
		n = n * 3 + 1;
		gaps[i] = n;
	}
	return (gaps);
}

/**
 * shell_sort - sorts an array of integers in ascending order using
 * the Shell sort algorithm, using the Knuth sequence
 *
 * @array: the array
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
	int *gaps = knuth_sequence(size);
	int temp;
	size_t gap, k, i, j;

	if (array == NULL || size <= 1)
		return;

	if (size == 2)
	{
		if (array[0] > array[1])
		{
			temp = array[0];
			array[0] = array[1];
			array[1] = temp;
		}
		return;
	}

	for (k = 0; k < size / 3; k++)
	{
		gap = gaps[k];
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			for (j = i; ((j >= gap) && (array[j - gap] > temp)); j--)
			{
				array[j] = array[j - gap];
			}
			array[j] = temp;
			if (j == 0)
				print_array(array, size);
		}
	}
}
