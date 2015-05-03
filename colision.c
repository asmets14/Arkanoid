/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colision.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvagner <rvagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 19:25:36 by rvagner           #+#    #+#             */
/*   Updated: 2015/05/03 22:43:46 by rvagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

static int		check_collision(t_bal *bal, t_brick *b)
{
	if (bal->x1 - 0.02 <= b->x + b->tx && bal->y1 - 0.02 <= b->y &&
			bal->x1 + 0.02 >= b->x && bal->y1 + 0.02 >= b->y + b->ty)
		return (1);
	return (0);
}

static void		modif_dir(t_bal *bal, t_brick *b)
{
	float	h1;
	float	h2;
	float	v1;
	float	v2;

	h1 = b->y - (bal->y1 - 0.02);
	h2 = (bal->y1 + 0.02) - (b->y + b->ty);
	v1 = (bal->x1 + 0.02) - b->x;
	v2 = (b->x + b->tx) - (bal->x1 - 0.02);
	if (h1 < h2 && h1 <= v1 && h1 <= v2)
		bal->dir_y *= -1;
	if (h2 < h1 && h2 <= v1 && h2 <= v2)
		bal->dir_y *= -1;
	if (v1 <= h1 && v1 <= h2 && v1 < v2)
		bal->dir_x *= -1;
	if (v2 <= h1 && v2 <= h2 && v2 < v1)
		bal->dir_x *= -1;
}

static void		check_bricks(t_bal *bal, t_env *e, t_brick b)
{
	while (e->map[b.i])
	{
		b.x = -0.99;
		b.j = 0;
		while (e->map[b.i][b.j])
		{
			if (e->map[b.i][b.j] != '0')
			{
				if (check_collision(bal, &b) == 1)
				{
					modif_dir(bal, &b);
					if (e->map[b.i][b.j] != '4')
					{
						e->map[b.i][b.j] -= 1;
						e->score += 1;
					}
					return ;
				}
			}
			b.j++;
			b.x += b.tx + 0.01;
		}
		b.i++;
		b.y += b.ty - 0.01;
	}
}

static void		check_walls(t_bal *bal, t_env *e)
{
	if (bal->x1 <= -1.0)
		bal->dir_x *= -1.5;
	if (bal->x1 >= 1.0)
		bal->dir_x *= -1;
	if (bal->y1 >= 0.86)
		bal->dir_y *= -1;
	if (bal->y1 <= -0.87 && (bal->x1 >= e->x_bar &&
				bal->x1 <= (e->x_bar + 0.25)))
	{
		bal->dir_y = 1;
		bal->dir_x *= 1.5;
	}
}

void			move_bal(t_bal *bal, t_env *e)
{
	t_brick		b;

	init_brick(&b);
	check_bricks(bal, e, b);
	check_walls(bal, e);
	if (bal->y1 < -0.97 && e->lives == 1)
	{
		ft_putstr("Ton score : ");
		ft_putnbr(e->score);
		ft_putstr("\n");
		sleep(2);
		exit(2);
	}
	else if (bal->y1 < -0.97)
	{
		e->lives -= 1;
		init_val(bal);
		e->space = 0;
	}
	normalize(bal);
	bal->x1 += (SPEED * bal->norm_x);
	bal->y1 += (SPEED * bal->norm_y);
}
