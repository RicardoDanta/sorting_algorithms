#include "sort.h"
/**
 * change - a function that changes nodes
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
 * insertion_sort_list - a function that order a doubly linkedlist
 * @list: Something
 * Return: 0
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *lastone;
	listint_t *aux;

	if (!list || !((*list)->next))
		return;

	aux = (*list)->next;
	lastone = *list;
	for (; aux ;)
	{
		if (lastone->n > aux->n)
		{
			aux = change(list, aux, lastone);
			lastone = aux->prev;
			while (lastone != NULL)
			{
				if (lastone->n > aux->n)
				{
					aux = change(list, aux, lastone);
					lastone = aux;
				}
				lastone = lastone->prev;
			}
		}
		lastone = aux;
		aux = aux->next;
	}
}
