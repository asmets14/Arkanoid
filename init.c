/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvagner <rvagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 20:03:25 by rvagner           #+#    #+#             */
/*   Updated: 2015/05/03 22:41:19 by rvagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

void init_val(t_bal *bal)
{
	bal->y1 = -0.87;
	bal->radius = 0.02;
	bal->dir_x = 1;
	bal->dir_y = 1;
}

void init_brick(t_brick *brick)
{
	brick->i = 0;
	brick->x = -0.99;
	brick->y = 0.9;
	brick->tx = 0.189;
	brick->ty = -0.08;
}

void init_env(t_env *e)
{
	e->pauz = 1;
	e->width = 1200;
	e->height = 1200;
	e->x_bar = 0;
	e->space = 0;
	e->score = 0;
	e->lives = 3;
}

void init_window(t_env *e)
{
	if (!glfwInit())
		exit(2);
	if (!(e->window = glfwCreateWindow(e->width, e->height,
					"Arkanoid", NULL, NULL)))
	{
		glfwTerminate();
		exit(2);
	}
}
