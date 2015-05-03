/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singleton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvagner <rvagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 21:28:45 by rvagner           #+#    #+#             */
/*   Updated: 2015/05/03 21:30:05 by rvagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

t_env		*ft_singleton(t_env *ptr)
{
	static t_env *save = NULL;

	if (ptr)
		save = ptr;
	return (save);
}

void		normalize(t_bal *bal)
{
	float tmp;

	tmp = ft_sqrt2(bal->dir_x * bal->dir_x * bal->dir_y * bal->dir_y);
	bal->norm_x = bal->dir_x / tmp;
	bal->norm_y = bal->dir_y / tmp;
}
