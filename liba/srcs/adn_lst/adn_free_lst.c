#include <stdlib.h>
#include "adn_lst.h"

void adn_free_lst(t_lst *list)
{
	t_elem *elem;
	t_elem *next;

	elem = list->head;
	while (elem->next)
	{
		next = elem->next;
		elem->next = NULL;
		free (elem);
		elem = next;
	}
	free (list);
}