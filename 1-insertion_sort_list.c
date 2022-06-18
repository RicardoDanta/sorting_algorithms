#include "sort.h"
/**
 * _cambio - cambiar nodos
 * @aux: Something
 * @previo: Something
 * @h: Something
 * Return: list
 */
void *_cambio(listint_t **h, listint_t *aux, listint_t *previo)
{
	listint_t *anterior = NULL, *siguiente = NULL;

	if (previo->prev)
		anterior = previo->prev;

	if (aux->next)
		siguiente = aux->next;

	if (anterior)
		anterior->next = aux;

	if (siguiente)
		siguiente->prev = previo;

	aux->next = previo;
	aux->prev = anterior;

	if (anterior == NULL)
		*h = aux;

	previo->next = siguiente;
	previo->prev = aux;

	print_list(*h);

	return (aux);
}

/**
 * insertion_sort_list - ordenar una doubly linkedlist
 * @list: doubly linkedlist
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *anterior;
	listint_t *aux;

	if (!list || !((*list)->next))
		return;

	aux = (*list)->next;
	anterior = *list;
	for (; aux ;)
	{
		if (anterior->n > aux->n)
		{
			aux = _cambio(list, aux, anterior);
			anterior = aux->prev;
			while (anterior != NULL)
			{
				if (anterior->n > aux->n)
				{
					aux = _cambio(list, aux, anterior);
					anterior = aux;
				}
				anterior = anterior->prev;
			}
		}
		anterior = aux;
		aux = aux->next;
	}
}
