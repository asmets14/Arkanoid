/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adn_arr_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmets <asmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 14:07:50 by asmets            #+#    #+#             */
/*   Updated: 2015/02/19 14:07:57 by asmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <adn_arr.h>
#include <stdlib.h>

void *adn_arr_new(size_t size)
{
	void **arr;

	arr = malloc(sizeof(void *) * (size + 1));
	arr[0] = NULL;
	return ((void *)arr);
}
