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
 * iLeftChild - Returns the left child of a node
 *
 * @i: The node
 * Return: size_t
 */
size_t iLeftChild(size_t i)
{
	return (2 * i + 1);
}

/**
 * siftDown - Repair the heap whose root element is at index 'start',
 * assuming the heaps rooted at its children are valid
 *
 * @array: The array to be repaired
 * @start: start index
 * @end: end index
 * @size: The array size
 */
void siftDown(int *array, size_t start, size_t end, size_t size)
{
	size_t root = start;
	size_t child, swap;

	while (iLeftChild(root) <= end)
	{
		child = iLeftChild(root);
		swap = root;

		if (array[swap] < array[child])
			swap = child;

		if (child + 1 <= end && array[swap] < array[child + 1])
			swap = child + 1;
		if (swap == root)
			return;

		swap_int_array(array, root, swap, size);
		root = swap;
	}
}

/**
 * heapify - Build the heap in array a so that largest value
 * is at the root
 * @array: The array
 * @size: The array size
 */
void heapify(int *array, size_t size)
{
	long start;

	/* start from the parent of the last element in the array */
	start = (((size - 1) - 1) / 2);

	while (start >= 0)
	{
		siftDown(array, start, size - 1, size);
		start -= 1;
	}
}

/**
 * heap_sort -  sorts an array of integers in ascending order
 * using the Heap sort algorithm
 *
 * @array: The array to be sorted
 * @size: The array size
 */
void heap_sort(int *array, size_t size)
{
	long end;

	if (array == NULL || size <= 1)
		return;
	heapify(array, size);
	end = size - 1;

	while (end > 0)
	{
		swap_int_array(array, end, 0, size);
		end -= 1;
		siftDown(array, 0, end, size);
	}
}
