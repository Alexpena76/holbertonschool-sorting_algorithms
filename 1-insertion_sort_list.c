#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending order
 * @list: Double pointer to the head of the double linked list
 *
 * Return: Void function
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *next_node, *position;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}

	current = (*list)->next;

	while (current != NULL)
	{
		next_node = current->next;
		position = current->prev;

		while (position != NULL && position->n > current->n)
			position = position->prev;

		if (position != current->prev)
		{
			if (current->prev != NULL)
				current->prev->next = current->next;
			else
				*list = current->next;

			if (current->next != NULL)
				current->next->prev = current->prev;

			if (position == NULL)
			{
				current->prev = NULL;
				current->next = *list;

				if (*list != NULL)
					(*list)->prev = current;

				*list = current;
			}
			else
			{
				current->prev = position;
				current->next = position->next;

				if (position->next != NULL)
					position->next->prev = current;

				position->next = current;
			}

			print_list(*list);
		}

		current = next_node;
	}
}
