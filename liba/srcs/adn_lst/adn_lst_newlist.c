/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adn_lst_newlist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmets <asmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 14:18:59 by asmets            #+#    #+#             */
/*   Updated: 2015/02/19 14:19:02 by asmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <adn_lst.h>
#include <stdlib.h>

t_lst *adn_lst_newlist(void)
{
	t_lst *list;

	list = (t_lst *)malloc(sizeof(t_lst));
	list->head = NULL;
	return (list);
}
