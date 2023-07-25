#include <stddef.h>
#include "sort.h"

/**
 * swap - swap two nodes of a doubly linked list
 * @first: The first node
 * @second: The second node
 * @head: Holds the address of the head
 * Return: void
 */
void swap(listint_t *first, listint_t *second, listint_t **head)
{
	listint_t *prevFirst = first->prev;
	listint_t *nextSecond = second->next;
	listint_t *nextFirst;
	listint_t *prevSecond;

	if (first == second)
		return;
	if ((prevFirst && prevFirst == nextSecond) || prevFirst == second)
	{
		prevFirst = first;
		first = second;
		second = prevFirst;

		prevFirst = first->prev;
		nextSecond = second->next;
	}
	nextFirst = first->next;
	prevSecond = second->prev;
	if (nextFirst == second)
	{
		second->next = first;
		first->prev = second;
	}
	else
	{
		second->next = nextFirst;
		if (nextFirst)
			nextFirst->prev = second;
		first->prev = prevSecond;
		if (prevSecond)
			prevSecond->next = first;
	}
	first->next = nextSecond;
	if (nextSecond)
		nextSecond->prev = first;
	second->prev = prevFirst;
	if (prevFirst)
		prevFirst->next = second;
	*head = first->prev ? *head : first;
	*head = second->prev ? *head : second;
}

/**
 * cocktail_sort_list - This is a function that sorts a doubly linked list
 * in ascending order using the cocktail sort algorithm
 *
 * The linked list is printed each time a swap occurs
 *
 * @list: Head of the linked list
 * Returns: void (the linked list is sorted in-place)
 */
 void cocktail_sort_list(listint_t **list)
{
	listint_t *start = NULL, *stop = NULL, *curr;
	int swapped = 0;

	if (list == NULL || *list == NULL || (*list)->next)
		return;
	curr = (*list);
	do {
		while (curr->next && curr != stop)
		{
			if (curr->n > curr->next->n)
			{
				swap(curr, curr->next, list);
				swapped = 1;
				print_list(*list);
			}
			else
				curr = curr->next;
		}
		if (!swapped)
			return;
		stop = (stop == NULL ? curr: stop->prev);
		curr = stop;
		while (curr->prev && curr != start)
		{
			if (curr->prev->n > curr->n)
			{
				swap(curr->prev, curr, list);
				print_list(list);
			}
			else
				curr = curr->prev;
		}
		start = (start == NULL ? curr : start->next);
	} while (start->n < stop->n);
}
