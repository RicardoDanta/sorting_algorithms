#include "sort.h"

/**
 * selection_sort - a function that sorts an array of integers
 * in ascending order using the Selection sort algorithm
 * @array: Something
 * @size: Something
 */
void selection_sort(int *array, size_t size)
{
	size_t i;
	size_t j;
	size_t compare;
	size_t aux;

	if (array == NULL)
		return;

	for (i = 0; i < size - 1; i++)
	{
		compare = i;

		for (j = i + 1; j < size; j++)
			if (array[j] < array[compare])
				compare = j;

		aux = array[i];
		array[i] = array[compare];
		array[compare] = aux;
	if (compare != i)
		print_array(array, size);
	}
}
