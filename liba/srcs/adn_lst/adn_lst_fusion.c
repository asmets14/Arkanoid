/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adn_lst_fusion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmets <asmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 14:16:51 by asmets            #+#    #+#             */
/*   Updated: 2015/02/19 14:18:34 by asmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <adn_lst.h>

void adn_lst_fusion(t_elem *elem1, t_elem *elem2)
{
	if (elem2)
		elem2->prev = elem1;
	if (elem1)
		elem1->next = elem2;
}
