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
 * print_db_linklist - handles the printing of the double list
 *
 * @buffer: list to be printed
 */
void print_db_linklist(listint_t *buffer)
{
	while (buffer->prev)
		buffer = buffer->prev;
	for (; buffer; buffer = buffer->next)
	{
		if (buffer->prev)
			printf(", %d", buffer->n);
		else
			printf("%d", buffer->n);
	}
	printf("\n");
}

int *generate_knuth(int end)
{
    int *ar;
    unsigned int i, step, len_ar = 1;

    ar = malloc(sizeof(int)*len_ar);
    ar[len_ar-1] = 0;
    for (i=1; i<end; i++)
    {
        step = (_pow_recursion(3, i) - 1)/2;
        if (step > end)
            break;
        ar[len_ar-1] = step;
        ar[len_ar] = 0;
        ar = realloc(ar, ++len_ar);
    }
}

void shell_sort(int *array, size_t size)
{

}