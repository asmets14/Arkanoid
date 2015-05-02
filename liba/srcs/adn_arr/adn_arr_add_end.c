/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adn_arr_add_end.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmets <asmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 14:06:58 by asmets            #+#    #+#             */
/*   Updated: 2015/02/19 14:09:20 by asmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <adn_arr.h>

void adn_arr_add_end(void *arr, void *elem)
{
	void **tab;

	tab = arr;
	while (*tab)
		tab++;
	*tab = elem;
	tab++;
	*tab = NULL;
}
