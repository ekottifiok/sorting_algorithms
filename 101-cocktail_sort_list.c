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
 * move_forward - move the double list backward
 *
 * @main: the list to be moved
 * @flag: the flag to show it's sorted
 */
void move_forward(listint_t **main, int *flag)
{
	listint_t *buffer = *main, *node, *prev_node, *next_node;

	for (; buffer->next;)
	{
		prev_node = buffer->prev;
		next_node = buffer->next;
		node = buffer;
		if (node->n > next_node->n)
		{
			if (prev_node)
				prev_node->next = next_node;
			next_node->prev = prev_node;
			if (next_node->next != NULL)
				(next_node->next)->prev = node;
			node->next = next_node->next;
			next_node->next = node;
			node->prev = next_node;

			*flag = 1;
			print_db_linklist(*main);
		}
		else
		{
			buffer = buffer->next;
		}
	}
	*main = buffer;
}

/**
 * move_backward - move the double list backward
 *
 * @main: the list to be moved
 * @flag: the flag to show it's sorted
 */
void move_backward(listint_t **main, int *flag)
{
	listint_t *buffer = *main, *node, *prev_node, *next_node;

	for (; buffer->prev;)
	{
		prev_node = buffer->prev;
		next_node = buffer->next;
		node = buffer;
		if (node->n < prev_node->n)
		{
			if (prev_node)
				prev_node->next = next_node;
			next_node->prev = prev_node;
			node->next = prev_node;
			node->prev = prev_node->prev;
			if (prev_node)
			{
				if (prev_node->prev != NULL)
					(prev_node->prev)->next = node;
				prev_node->prev = node;
			}
			*flag = 1;
			print_db_linklist(*main);
		}
		else
		{
			buffer = buffer->prev;
		}
	}
	*main = buffer;
}

/**
 * cocktail_sort_list - sorts double linked list
 *
 * @list: double linked list to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *buffer;
	int sort_flag;

	if (!list || !(*list))
		return;
	buffer = *list;
	while (buffer->prev)
		buffer = buffer->prev;

	for (buffer = *list, sort_flag = 1; sort_flag; buffer = *list)
	{
		sort_flag = 0;
		move_forward(&buffer, &sort_flag);
		buffer = buffer->prev;
		move_backward(&buffer, &sort_flag);
	}
	while (buffer->prev)
		buffer = buffer->prev;
	*list = buffer;
}
