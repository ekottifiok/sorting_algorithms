#ifndef SORT_H
#define SORT_H
#include <stdio.h>
#include <stdlib.h>
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;
void swap_int_array(int *array, size_t i, size_t j, size_t size);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
size_t lomuto_partition(int *array, size_t low, size_t high, size_t size);
void quick_sort_r(int *array, long low, long high, size_t size);
unsigned int check_for_sort(int *array, size_t size);
void bubble_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void insertion_sort_list(listint_t **list);
void shell_sort(int *array, size_t size);
#endif
