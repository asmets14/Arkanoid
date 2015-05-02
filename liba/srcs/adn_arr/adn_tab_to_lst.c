/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adn_tab_to_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmets <asmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 14:08:04 by asmets            #+#    #+#             */
/*   Updated: 2015/02/19 14:14:48 by asmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <adn_lst.h>
#include <adn_arr.h>
#include <stdlib.h>

static int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char		*ft_strdup(char *str)
{
	char	*name;
	int		i;

	i = ft_strlen(str);
	name = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i])
	{
		name[i] = str[i];
		i++;
	}
	name[i] = '\0';
	return (name);
}

t_lst			*adn_tab_to_lst(char **tab)
{
	int		i;
	t_lst	*list;

	i = 0;
	list = adn_lst_newlist();
	while (tab[i])
	{
		adn_lst_put_end(list, adn_lst_newelem(ft_strdup(tab[i])));
		i++;
	}
	return (list);
}
