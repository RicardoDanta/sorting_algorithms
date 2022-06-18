#include "sort.h"
/**
 * change - cambiar nodos
 * @aux: Something
 * @previous: Something
 * @h: Something
 * Return: 0
 */
void *change(listint_t **h, listint_t *aux, listint_t *previous)
{
	listint_t *lastone = NULL, *nxt = NULL;

	if (previous->prev)
		lastone = previous->prev;

	if (aux->next)
		nxt = aux->next;

	if (lastone)
		lastone->next = aux;

	if (nxt)
		nxt->prev = previous;

	aux->next = previous;
	aux->prev = lastone;

	if (lastone == NULL)
		*h = aux;

	previous->next = nxt;
	previous->prev = aux;

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
