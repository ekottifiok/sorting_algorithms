#include "sort.h"

/**
 * check_for_sort - checks if the array is sorted
 *
 * @array: the array to be checked
 * @size: the size of the array
 * Return: unsigned int 0 for sorted and 1 for not
 */
unsigned int check_for_sort(int *array, size_t size)
{
	unsigned int iter;

	for (iter = 1; iter < size; iter++)
	{
		if (array[iter - 1] > array[iter])
			return (1);
	}
	return (0);
}

/**
 * bubble_sort - sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 *
 * @array: the array to be sorted
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	unsigned int iter, sorted_flag = 1, buffer, size_buf;

	for (iter = 1, size_buf = size; sorted_flag; iter++)
	{
		if (iter == size_buf)
		{
			iter = 1;
			size_buf--;
		}
		if (array[iter - 1] > array[iter])
		{
			print_array(array, size);
			buffer = array[iter - 1];
			array[iter - 1] = array[iter];
			array[iter] = buffer;
		}
		sorted_flag = check_for_sort(array, size);
	}
}
