/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gere_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvagner <rvagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 19:03:44 by rvagner           #+#    #+#             */
/*   Updated: 2015/05/03 19:14:50 by rvagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

int			map_end(t_env *e)
{
	int		i;
	int		j;

	i = 0;
	while (e->map[i])
	{
		j = 0;
		while (e->map[i][j])
		{
			if (e->map[i][j] > '0' && e->map[i][j] < '4')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void		change_map(t_env *e)
{
	if (e->curr_map == 1)
	{
		e->map = get_map("level/level2.txt");
		e->curr_map = 2;
	}
	else if (e->curr_map == 2)
	{
		e->map = get_map("level/level3.txt");
		e->curr_map = 3;
	}
	else if (e->curr_map == 3)
	{
		ft_putstr("Bravo, vous avez fini !\nScore : ");
		ft_putnbr(e->score);
		ft_putstr(" !\n");
		exit(0);
	}
}
