#include "adn_lst.h"
#include <stdlib.h>
char **adn_lst_to_tab(t_lst *list,  char **tab)
{
	int i;
	t_elem *elem;

	elem = list->head;
	i = 0;
	while(elem)
	{	
		tab[i] = elem->data;
		elem = elem->next;
		i++;
	}
	tab[i] = NULL;
	adn_free_lst(list);
	list = NULL;
	return (tab);
}
