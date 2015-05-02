/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adn_lst_newelem.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmets <asmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 14:18:45 by asmets            #+#    #+#             */
/*   Updated: 2015/02/19 14:20:19 by asmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <adn_lst.h>
#include <stdlib.h>

/*
**creation new element pour liste chainee
*/
t_elem *adn_lst_newelem(void *data)
{
	t_elem *elem;

	elem = (t_elem *)malloc(sizeof(t_elem));
	elem->data = data;
	elem->next = NULL;
	elem->prev = NULL;
	return (elem);
}
