#include "sort.h"

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

/**
 * insertion_sort_list - sorts a doubly linked list of integers in
 * ascending order
 *
 * @list: the double linked list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *buffer = *list;

	while (buffer->prev)
		buffer = buffer->prev;

	for (buffer = buffer->next; buffer; buffer = buffer->next)
	{
		for (; buffer->n < (buffer->prev)->n;)
		{
			if (buffer->prev)
				(buffer->prev)->next = buffer->next;
			if (buffer->next)
				(buffer->next)->prev = (buffer->prev);

			buffer->next = buffer->prev;
			buffer->prev = (buffer->prev)->prev;
			if (buffer->next)
				(buffer->next)->prev = buffer;
			if (buffer->prev)
				(buffer->prev)->next = buffer;
			else
				break;
		}
		print_db_linklist(*list);
	}
	while ((*list)->prev)
		*list = (*list)->prev;
}
