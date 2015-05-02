/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adn_ispunct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmets <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/25 12:15:03 by asmets            #+#    #+#             */
/*   Updated: 2015/03/25 12:15:07 by asmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "adn_ctype.h"

/*
** Trouve une ponctuation
*/
int		adn_ispunct(int c)
{
	if (c >= 33 && c <= 47)
		return (1);
	else if (c >= 58 && c <= 64)
		return (1);
	else if (c >= 91 && c <= 96)
		return (1);
	else if (c >= 123 && c <= 126)
		return (1);
	else
		return (0);
}
