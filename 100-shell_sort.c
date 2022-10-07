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

size_t generate_knuth(int **a, int end)
{
    int *ar = *a;
    unsigned int i, step;
    size_t len_ar = 1;

    ar = malloc(sizeof(int)*len_ar);
    ar[0] = 0;
    for (i=1; i<end; i++, len_ar++)
    {
        step = (_pow_recursion(3, i) - 1)/2;
        if (step > end)
            break;
        ar[len_ar-1] = step;
        ar = realloc(ar, len_ar+1);
        ar[len_ar] = 0;
    }
    return len_ar;
}

void shell_sort(int *array, size_t size)
{
    int *ar;
    print_array(ar, generate_knuth(&ar, 6));
}