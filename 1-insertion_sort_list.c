#include "sort.h"
/**
 * insertion_sort_list - it sorts a doubly linkedlist
 * of integers in ascending orde
 * @list: The list to be sorted
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *actual, *swap, *previous;

	if (!list || !*list)
		return;

	actual = *list;
	while ((actual = actual->next))
	{
		swap = actual;
		while (swap->prev && swap->n < swap->prev->n)
		{
			previous = swap->prev;
			if (swap->next)
				swap->next->prev = previous;
			if (previous->prev)
				previous->prev->next = swap;
			else
				*list = swap;
			previous->next = swap->next;
			swap->prev = previous->prev;
			swap->next = previous;
			previous->prev = swap;
			print_list(*list);
		}
	}
}
