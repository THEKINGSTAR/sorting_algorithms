#include "sort.h"

/**
 * _insertion_sort_list - implementation insertion_sort algorithm
 *
 * @list: input linked list
 * You are not allowed to modify the integer n of a node.
 * You have to swap the nodes themselves.
 * You’re expected to print the list
 * after each time you swap two elements
 *
 * Return: FUNCTION DO NOT RETURN
 */
void _insertion_sort_list(listint_t **list)
{
	listint_t *curnt, *curs, *prev, *head;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	curnt = *list;
	head = *list;
	curs = head;
	while (curs != NULL)
	{
		/*Check curser is advanced correctlly*/
		/*printf("CURSER VAL NW IS:%d\n",curs->n);*/
		/* Check curnt is advanced correctlly */
		/*printf("CURRENT VALUE NOW IS: %d \n", curnt->n);*/
		while (curnt->next != NULL)
		{
			if (curnt->n > curnt->next->n)
			{
				printf("COMPAREV BETWEEN CURNT %d, NEXT %d , AND SWITCH BOTH VLUES!!I\n\n",
						curnt->n, curnt->next->n);
				/* |5| |3| |4| |6| */
				/*  p   c   n  cnn */
				prev = curnt->prev;
				prev->next = curnt->next;
				/* p --> n */
				prev->next->prev = prev;
				/* p <-- n */
				curnt->next = prev->next->next;
				/* c --> cnn */
				curnt->next->prev = curnt;
				curnt->prev = prev->next;
				print_list(*list);
			}
			else
			{	curnt = curnt->next;	}
			curnt = curnt->next;
		}
		curs = curs->next;
	}
	*list = head;
}





/**
 * insertion_sort_list - implementation insertion_sort algorithm
 *
 * @list: input linked list
 * You are not allowed to modify the integer n of a node.
 * You have to swap the nodes themselves.
 * You’re expected to print the list
 * after each time you swap two elements
 *
 * Return: FUNCTION DO NOT RETURN
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *next, *prev;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	curr = (*list)->next;

	while (curr != NULL)
	{
		next = curr->next;
		prev = curr->prev;

		while (prev != NULL && prev->n > curr->n)
		{
			prev->next = curr->next;
			if (curr->next != NULL)
				curr->next->prev = prev;

			curr->next = prev;
			curr->prev = prev->prev;
			prev->prev = curr;

			if (curr->prev != NULL)
				curr->prev->next = curr;
			else
				*list = curr;

			print_list(*list);

			prev = curr->prev;
		}

		curr = next;
	}
}
