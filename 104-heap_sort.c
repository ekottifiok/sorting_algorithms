#include "sort.h"


void heapify(int **arr, int i, size_t len_arr)
{
    size_t left = 2 * i, right = (2 * i + 1);
    int *holder = *arr, max, buffer;

    if (left <= len_arr && holder[left] > holder[i])
        max = left;
    else
        max = i;
    if (right <= len_arr && holder[right] > holder[max])
        max = right;
    if (max != i)
    {
        buffer = holder[i];
        holder[i] = holder[max];
        holder[max] = buffer;        
        heapify(arr, max, len_arr);
    }
}

void build_max_heap(int **arr, size_t len_arr)
{
    int iter;

    for (iter = (len_arr-1) / 2; iter >= 0; iter--)
    {    
        heapify(arr, iter, len_arr);
        print_array(*arr, len_arr);
    }
}

void heap_sort(int *array, size_t size)
{
    int iter, buffer, size_buffer = size-1;

    build_max_heap(&array, size);
    print_array(array, size);
    for (iter = size_buffer; iter > 0; iter--)
    {
        buffer = array[0];
        array[0] = array[iter];
        array[iter] = buffer;
        print_array(array, size);
        size_buffer--;
        heapify(&array, 0, size_buffer);
        print_array(array, size);
    }
}