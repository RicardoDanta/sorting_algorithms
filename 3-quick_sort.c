#include "sort.h"
/**
 * _lomuto - posicionar pivote como el ultimo elemento
*usando el esquema de fraccionamiento de Lomuto
 * @array: array a ordenar
 * @size: tamano de la array
 * @inicio: limite del inicio
 * @final: limite del final
 * Return: array con pivote
 **/
int _lomuto(int *array, size_t size, int inicio, int final)
{
	int pivot, pivIndex, aux, cont;

	pivot = array[final];
	pivIndex = inicio - 1;

	for (cont = inicio; cont < final; cont++)
	{
		if (array[cont] < pivot)
		{
			pivIndex += 1;
			if (cont != pivIndex)
			{
				aux = array[cont];
				array[cont] = array[pivIndex];
				array[pivIndex] = aux;
				print_array(array, size);
			}
		}
	}
	if (array[final] < array[pivIndex + 1])
	{
		aux = array[pivIndex + 1];
		array[pivIndex + 1] = array[final];
		array[final] = aux;
		print_array(array, size);
	}
	return (pivIndex + 1);
}

/**
 * _recursion - ordena una array usando quick sort
 * @array: array a ordenar
 * @size: tamano de la array
 * @inicio: limite del inico
 * @final: limite del final
 **/
void _recursion(int *array, size_t size, int inicio, int final)
{
	int pivIndex;

	if (inicio >= final)
		return;

	pivIndex = _lomuto(array, size, inicio, final);
	_recursion(array, size, inicio, pivIndex - 1);
	_recursion(array, size, pivIndex + 1, final);
}

/**
 * quick_sort - ordenar una array de forma ascendente
 * @array: array
 * @size: tamano de la array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 1)
		return;

	_recursion(array, size, 0, size - 1);
}
