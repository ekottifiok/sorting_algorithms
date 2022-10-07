#include "sort.h"

/**
 * getNode - Gets the node at a given index
 *
 * @list: The list to be tranversed
 * @idx: The index
 *
 * Return: (listint_t) the found Node or NULL
 */
listint_t *getNode(listint_t **list, size_t idx)
{
	listint_t *node = NULL;
	size_t i;

	node = *list;
	for (i = 0; node != NULL; i++)
	{
		if (i == idx)
			return (node);
		node = node->next;
	}
	return (node);
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers in
 * ascending order
 *
 * @list: the double linked list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *inode, *node, *prev, *next;
	int i, j;

	if (list == NULL)
		return;

			inode = *list;
	for (i = 0; inode != NULL; i++)
	{
		j = i;
		node = getNode(list, j);
		while (j > 0 && node && node->prev && node->prev->n > node->n)
		{
			prev = node->prev;
			next = node->next;
			node->prev = NULL;
			node->next = NULL;

			node->prev = prev->prev;
			if (prev->prev != NULL)
				prev->prev->next = node;
			if (prev->prev == NULL)
				*list = node;

			prev->next = next;
			if (next != NULL)
				next->prev = prev;
			prev->prev = node;
			node->next = prev;
			print_list(*list);

			j -= 1;
			node = getNode(list, j);
		}
		inode = inode->next;
	}
}
