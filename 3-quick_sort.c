#include "sort.h"

/**
 * quick_sort - a function that sorts an array of integers
 * in ascending order using the Quick sort algorithm
 * @array: Something
 * @size: Something
 * Return: 0
 */
void quick_sort(int *array, size_t size)
{
	int i;
	int j;
	int pivot;
