#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in
 * ascending order
 * 
 * @list the double linked list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *buffer = *list, *holder;
    unsigned int sorted = 1;

    
    while (buffer->prev)
        buffer = buffer->prev;
    
   for (buffer = buffer->next; buffer->next; buffer = buffer->next)
   {
       while ((buffer->prev)->n > buffer->n)
            continue;
   }
}