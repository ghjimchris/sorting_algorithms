#include "sort.h"
/**
 * selection_sort - sorts an array of integers in ascending order
 * using the selection sort algorithm
 * @array: array
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, k, min, tmp;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (k = i + 1; k < size; k++)
		{
			if (array[k] < array[min])
				min = k;
		}
		if (min != i)
		{
			tmp = array[i];
			array[i] = array[min];
			array[min] = tmp;
			print_array(array, size);
		}
	}
}
