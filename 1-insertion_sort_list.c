#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 *                       using the Insertion sort algorithm
 * @list: pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *tmp;

	if (!list || !*list || !(*list)->next)
		return;

	curr = (*list)->next;
	while (curr)
	{
		tmp = curr;
		while (tmp->prev && tmp->n < tmp->prev->n)
		{
			/* detach tmp */
			tmp->prev->next = tmp->next;
			if (tmp->next)
				tmp->next->prev = tmp->prev;

			/* move tmp backward */
			tmp->next = tmp->prev;
			tmp->prev = tmp->prev->prev;

			if (tmp->prev)
				tmp->prev->next = tmp;
			else
				*list = tmp;

			tmp->next->prev = tmp;

			print_list(*list);
		}
		curr = curr->next;
	}
}
