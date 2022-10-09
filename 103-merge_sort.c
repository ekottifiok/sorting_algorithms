#include "sort.h"


/**
 * top_down_merge -  
 * Left source half is A[ iBegin:iMiddle-1].
 * Right source half is A[iMiddle:iEnd-1   ].
 * Result is            B[ iBegin:iEnd-1   ].
 * 
 * @buffer 
 * @start: start of the array
 * @mid: mid point of the array
 * @end: end point of the array
 * @param array 
 */
void top_down_merge(int **buffer_p, int start, int mid, int end, int **array_p)
{
    int iter, start_buf = start, mid_buf = mid, *array = *array_p, *buffer=*buffer_p;
    print_array(buffer, end);
    printf("Merging...\n");
    printf("[left]: ");
    print_array(array+start, mid-1);
    printf("[right]: ");
    print_array(array+mid, end);
    
    /* While there are elements in the left or right runs... */
    for (iter = start; iter < end; iter++)
    {
        /* If left run head exists and is <= existing right run head. */
        if (start_buf < mid && (mid_buf >= end || buffer[start_buf] <= buffer[mid_buf]))
        {
            array[iter] = buffer[start_buf];
            start_buf += 1;
        }
        else
        {
            array[iter] = buffer[mid_buf];
            mid_buf += 1;
        }
    }
    *array_p = array;
    *buffer_p = buffer;
    printf("Done");
    print_array(*array_p, end-1);
}

/**
 * top_down_split_merge -  
 * Split A[] into 2 runs, sort both runs into B[], merge both runs from B[] to A[]
 * iBegin is inclusive; iEnd is exclusive (A[iEnd] is not in the set).
 * 
 * @param buff 
 * @param start 
 * @param end 
 * @param main_array 
 */
void top_down_split_merge(int **buff, int start, int end, int **main_array)
{
    int mid;

    if (end - start <= 1)
        return;
    /* split the run longer than 1 item into halves */
    mid = (start+end)/2;
    /* recursively sort both runs from array A[] into B[] 
     * sort the left  run
     */
    
    top_down_split_merge(main_array, start, mid, buff);
    /* sort the right run */
    top_down_split_merge(main_array, mid, end, buff);
    /* merge the resulting runs from array B[] into A[] */
    top_down_merge(buff, start, mid, end, main_array);
}

/**
 * merge_sort - implementation of the merge sort 
 * 
 * @array: array to be sorted
 * @size: size of the array
 */
void merge_sort(int array[], size_t size)
{
    int *buffer, i;

    buffer = malloc(sizeof(int)*size+1);
    for (i =0; i < size; i++)
        buffer[i]= array[i];

    top_down_split_merge(&buffer, 0, size, &array);   // sort data from B[] into A[]
    print_array(array, size);
    free(buffer);
}