/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adn_isdigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmets <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/25 12:14:35 by asmets            #+#    #+#             */
/*   Updated: 2015/03/25 12:14:41 by asmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "adn_ctype.h"

/*
** caractere numerique
*/
int adn_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
