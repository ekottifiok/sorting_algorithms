
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

void insertion_sort_list(listint_t **list)
{

}