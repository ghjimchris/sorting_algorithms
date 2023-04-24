#include "sort.h"

/**
 * swap - swaps two integers
 * @a: first input address
 * @b: second input address
 *
 * Return: Nothing
 */
void swap(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

/**
 * shell_sort - quick sort algorithm
 * @array: array of integers to be sorted
 * @size: size of array
 *
 * Return: Nothing
 */
void shell_sort(int *array, size_t size)
{
	listint_t *seq = NULL, *seqq;
	int n;
	long int j;
	size_t i, k, a, c;

	if (array == NULL || size <= 1)
		return;
	seq = knuth_seq(size);
	seqq = seq;
	if (!seq)
		return;
	while (seq)
	{
		n = seq->n;
		for (k = 0; k < (size_t)n; k++)
		{
			for (i = n + k; i < size; i += n)
			{
				a = i;
				j = i - n;
				c = 0;
				while (j >= 0)
				{
					c++;
					if (j < 0)
						break;
					if (array[i] >= array[j])
						break;
					swap(&array[i], &array[j]);
					i -= n;
					j -= n;
				}
				i = a;
			}
		}
		print_array(array, size);
		seq = seq->next;
	}
	free(seqq);
}

/**
 * knuth_seq - Creates a doubly linked list of the required knuth sequence
 * @size: Size of the array requiring knuth sequencee
 *
 * Return: Pointer to the first element of the created list. NULL on failure
 */
listint_t *knuth_seq(size_t size)
{
	listint_t *list, *node;
	int k = 1, *tmp;

	list = NULL;
	while ((size / k) >= 2)
	{
		node = (listint_t *)malloc(sizeof(listint_t));
		if (!node)
			return (NULL);
		node->prev = NULL;
		node->next = list;
	tmp = (int *)&node->n;
		*tmp = k;
		list = node;
		k = (k * 3) + 1;
	}
	return (list);
}

/**
 * free_seq - frees the linked list that contains the knuth sequence
 * @list - knuth sequence
 *
 * Return: nothing
 */
void free_seq(listint_t *list)
{
	listint_t *temp;

	if (!list)
		return;
	temp = list;
	while (list)
	{
		list = list->next;
		free(temp);
		temp = list;
	}
}
