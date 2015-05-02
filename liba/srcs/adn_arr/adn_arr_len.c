/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adn_arr_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmets <asmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 14:07:29 by asmets            #+#    #+#             */
/*   Updated: 2015/02/19 14:13:35 by asmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <adn_arr.h>
#include <stddef.h>

size_t adn_arr_len(void *tab)
{
	size_t	len;
	void	**arr;

	arr = tab;
	len = 0;
	while (arr[len])
		len++;
	return (len);
}
