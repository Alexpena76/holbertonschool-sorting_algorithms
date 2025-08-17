#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending order
 * @list: Double pointer to the head of the double linked list
 *
 * Return: Void function
 */

void insertion_sort_list(listint_t **list)
{
    listint_t *current, *next_node;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    current = (*list)->next;

    while (current != NULL)
    {
        next_node = current->next;

        while (current->prev != NULL && current->prev->n > current->n)
        {
            swap_with_prev(list, current);
            print_list(*list);
        }

        current = next_node;
    }
}

void swap_with_prev(listint_t **list, listint_t *node)
{
    listint_t *prev = node->prev;

    if (prev->prev != NULL)
        prev->prev->next = node;
    else
        *list = node;
    

    if (node->next != NULL)
        node->next->prev = prev;

    prev->next = node->next;
    node->prev = prev->prev;
    node->next = prev;
    prev->prev = node;
}
