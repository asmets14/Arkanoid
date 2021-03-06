/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adn_isascii.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmets <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/25 12:14:25 by asmets            #+#    #+#             */
/*   Updated: 2015/03/25 12:14:29 by asmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "adn_ctype.h"

/*
** caractere ascii en decimal
*/
int adn_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
