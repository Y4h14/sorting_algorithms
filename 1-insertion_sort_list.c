#include "sort.h"

/**
 * insertion_sort_list - implementing the insertion sort algorithm
 * @list: the list to sort
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *itr;
	int n;

	if (list == NULL || (*list) == NULL)
		return;

	itr = *list;
	while (itr)
	{
		while (itr)
		{
			if (itr->next != NULL)
			{
				if (itr->n > itr->next->n)
				{
					n = itr->n;
					*(int *)&itr->n = itr->next->n;
					*(int *)&itr->next->n = n;
					itr = *list;
					print_list(itr);
					break;
				}
			}
			itr = itr->next;
		}
	}
}
