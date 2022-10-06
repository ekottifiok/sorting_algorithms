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
        if (array[iter -1] > array[iter])
            return (1);
    }
    return (0);
}