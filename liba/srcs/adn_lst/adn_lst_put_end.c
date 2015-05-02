/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adn_lst_put_end.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmets <asmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 14:19:10 by asmets            #+#    #+#             */
/*   Updated: 2015/02/19 14:20:52 by asmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <adn_lst.h>
#include <stdio.h>

void adn_lst_put_end(t_lst *list, t_elem *elem)
{
	t_elem *tmp;

	if (!list->head)
		list->head = elem;
	else
	{
		tmp = list->head;
		while (tmp->next)
			tmp = tmp->next;
		adn_lst_fusion(tmp, elem);
	}
}
