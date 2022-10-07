#include "sort.h"

/**
 * _pow_recursion - finds the power of number using recursion
 * @x: the base value example 10
 * @y: the power example 2
 * Return: returns the value of 10**2 which is 100
 */
int _pow_recursion(int x, int y)
{
	if (y < 0)
		return (-1);
	if (y == 0)
		return (1);
	return (x * _pow_recursion(x, y - 1));
}

/**
 * generate_knuth - generates the sequence
 *
 * @end: end value of the sequence
 * @len: length of the sequence
 * Return: int*
 */
int *generate_knuth(int end, int *len)
{
	int *ar, i, j, step, buffer, len_ar = 1;

	ar = malloc(sizeof(int) * len_ar);
	for (i = 1; i < end; i++, len_ar++)
	{
		step = (_pow_recursion(3, i) - 1) / 2;
		if (step > end)
			break;
		ar[len_ar - 1] = step;
		ar = realloc(ar, len_ar + 1);
	}
	*len = --len_ar;
	for (i = 0, j = len_ar - 1; i < len_ar / 2; i++, j--)
	{
		buffer = ar[i];
		ar[i] = ar[j];
		ar[j] = buffer;
	}

	return (ar);
}

/**
 * swap_array - swaps values in an array
 *
 * @array: the array to be swapped
 * @position: the position to be swapped
 * @step: the step before or after the position
 * Return: int
 */
int swap_array(int **array, int position, int step)
{
	int buffer;

	if (position + step < 0)
		return (0);
	buffer = (*array)[position];
	(*array)[position] = (*array)[position + step];
	(*array)[position + step] = buffer;
	return (1);
}

/**
 * shell_sort - sorts an array
 *
 * @array: the array
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
	int *gaps, len_gaps, j, k, sorts, gap, k_buf, s;

	gaps = generate_knuth(size, &len_gaps);
	for (sorts = 1, j = 0, gap = gaps[j]; sorts; gap = gaps[j])
	{

		sorts = 0;

		for (k = 0; k + gap < (int)size; k++)
		{
			if (array[k] < array[k + gap])
				continue;
			swap_array(&array, k, gap);
			sorts = 1;
			k_buf = k;

			while (k_buf - gap >= 0 && s && array[k_buf - gap] > array[k_buf])
			{
				s = swap_array(&array, k_buf, -gap);
				k_buf -= gap;
			}
		}
		if (j < len_gaps - 1)
		{
			print_array(array, size);
			j += 1;
		}
	}
	print_array(array, size);
}
