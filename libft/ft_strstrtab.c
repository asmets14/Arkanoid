/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstrtab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmets <asmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 13:32:21 by asmets            #+#    #+#             */
/*   Updated: 2015/02/12 13:32:58 by asmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* chercher mots dans une **tab*/

#include "libft.h"

char *ft_strstrtab(char **tab, char *word)
{
	int i;

	i = 0;
	while(tab[i] && (ft_strstr(tab[i], word) == 0))
		i++;
	return (tab[i]);
}
