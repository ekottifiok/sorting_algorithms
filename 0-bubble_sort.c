#include "sort.h"

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
			buffer = array[iter - 1];
			array[iter - 1] = array[iter];
			array[iter] = buffer;
		}
		sorted_flag = check_for_sort(array, size);
		print_array(array, size);
	}
}
