#include "sort.h"

/**
 * cocktail_sort_list - selection sort algorithm
 * @list: linked list of integers to be sorted
 *
 * Return: Nothing
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *temp, *temp2;
	int a = 1, b = 1;

	if (list == NULL || *list == NULL)
		return;
	temp = *list;
	while (temp->next)
	{
		temp2 = temp->next;
		if (temp->n > temp2->n)
		{
			a = 0;
			temp->next = temp2->next;
			if (temp->next)
				temp->next->prev = temp;
			temp2->prev = temp->prev;
			if (temp2->prev)
				temp2->prev->next = temp2;
			temp2->next = temp;
			temp->prev = temp2;
			temp->prev->next = temp;
			print_list(*list);
		}
		else
			temp = temp->next;
	}
	while (temp->prev)
	{
		temp2 = temp->prev;
		if (temp->n < temp2->n)
		{
			b = 0;
			temp->prev = temp2->prev;
			if (temp->prev)
				temp->prev->next = temp;
			temp2->next = temp->next;
			if (temp2->next)
				temp2->next->prev = temp2;
			temp2->prev = temp;
			temp->next = temp2;
			temp->next->prev = temp;
			if (temp->prev == NULL)
				*list = temp;
			print_list(*list);
		}
		else
			temp = temp->prev;
	}
	if (a && b)
		return;
	cocktail_sort_list(list);
}
