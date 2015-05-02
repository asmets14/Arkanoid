#include "adn_lst.h"

int adn_lst_len(t_lst *list)
{
	int len;
	t_elem *elem;

	elem = list->head;
	len = 0;
	while (1)
	{
		len++;
		if (elem->next == (void *)0)
			break ;
		elem = elem->next;
	}
	return (len);
}
