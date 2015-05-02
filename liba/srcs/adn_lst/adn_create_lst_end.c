
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adn_create_list_end.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmets <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 14:32:53 by asmets            #+#    #+#             */
/*   Updated: 2015/02/24 14:33:33 by asmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <adn_lst.h>

void adn_create_lst_end(t_lst *list, void *name)
{
	t_elem *elem;

	elem = adn_lst_newelem(name);
	adn_lst_put_end(list, elem);
}
