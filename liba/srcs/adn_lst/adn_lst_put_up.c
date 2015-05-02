/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adn_lst_put_up.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmets <asmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 14:19:22 by asmets            #+#    #+#             */
/*   Updated: 2015/02/19 14:19:25 by asmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <adn_lst.h>

void adn_lst_put_up(t_lst *list, t_elem *elem)
{
	t_elem *tmp;

	tmp = list->head;
	list->head = elem;
	adn_lst_fusion(list->head, tmp);
}
