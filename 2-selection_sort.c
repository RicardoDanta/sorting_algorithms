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
	size_t h;
	size_t aux;

	if (array == NULL)
		return;

	for (i = 0; i < size - 1; i++)
	{
		h = i;

		for (j = i + 1; j < size; j++)
			if (array[j] < array[h])
				h = j;

		aux = array[i];
		array[i] = array[h];
		array[h] = aux;
		print_array(array, size);
	}
}
