#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 * order using insertion sort
 * @list: list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL;

	if (list == NULL)
		return;
	current = (*list)->next;
	while (current != NULL)
	{
		while (current->prev != NULL && current->prev->n > current->n)
		{
			current->prev->next = current->next;
			if (current->next != NULL)
				current->next->prev = current->prev;
			current->next = current->prev;
			current->prev = current->next->prev;
			current->next->prev = current;
			if (current->prev == NULL)
				*list = current;
			else
				current->prev->next = current;
			print_list(*list);
		}
		current = current->next;
	}
}
