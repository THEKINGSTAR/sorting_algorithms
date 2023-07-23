#include "sort.h"


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
	size_t len, itr;
	int key;
	listint_t *in_lst, *curnt, *curs, *prev, *head;

	len = 0;
	curnt = *list;
	head = *list;
	while(curnt)
	{
		len++;
		curnt = curnt->next;
	}
	printf("LIST LEN = %ld\n",len);

	for (itr = 1; itr < len; itr++)
	{
		key = curnt->n;
		printf("KEY IS %d", key);
		prev = curnt->prev;
		while (prev != NULL && prev->n > key)
		{
			curs = prev->prev;
			if (prev->prev)
					prev->prev->next = curnt;
			else
				head = curnt;
			if (curnt->next)
			{
				curnt->next->prev = prev;
			}
			prev->next = curnt->next;
			curnt->prev = prev->prev;
			prev->prev = curnt;
			curnt->next = prev;
			

			prev = curs;
			print_list(head);
		}
	}
	*list = head;
}
