/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adn_print_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmets <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 14:38:01 by asmets            #+#    #+#             */
/*   Updated: 2015/02/24 14:39:23 by asmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <adn_lst.h>

void adn_print_lst(t_lst *list)
{
	t_elem *elem;

	elem = list->head;
	while (elem)
	{
		//ft_putendl(elem->data);
		elem = elem->next;
	}
}
