/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adn_arr_iter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmets <asmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 14:07:11 by asmets            #+#    #+#             */
/*   Updated: 2015/02/19 14:13:18 by asmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <adn_arr.h>

void	adn_arr_iter(void *arr, void (*f)(void *arr, void *context),
					void *context)
{
	char	**tab;
	int		i;

	i = 0;
	tab = arr;
	while (tab[i])
	{
		f(tab[i], context);
		i++;
	}
}
