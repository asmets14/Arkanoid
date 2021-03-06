/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvagner <rvagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 20:09:10 by rvagner           #+#    #+#             */
/*   Updated: 2015/05/03 22:49:01 by rvagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

char		**get_map(char *str)
{
	int		fd;
	int		ret;
	char	buf[89];

	if ((fd = open(str, O_RDONLY)) == -1)
	{
		ft_putendl_fd("Error I need a valid fd", 2);
		exit(2);
	}
	if ((ret = read(fd, buf, 88)) == -1)
	{
		ft_putendl_fd("Error read", 2);
		exit(2);
	}
	buf[ret] = '\0';
	return (ft_strsplit(buf, '\n'));
}

void		boucle_principal(t_bal *bal, t_brick *brick, t_env *e)
{
	t_seg	s;

	while (1)
	{
		if (map_end(e))
			change_map(e);
		if (glfwWindowShouldClose(e->window))
			break ;
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		draw_bricks(e, brick);
		draw_seg(&s, e);
		if (e->space == 0)
			bal->x1 = e->x_bar + 0.125;
		draw_circle(bal, e);
		draw_barre(e->x_bar, -0.90);
		if (e->space == 1 && e->pauz == 1)
			move_bal(bal, e);
		glfwSwapBuffers(e->window);
		glfwPollEvents();
	}
}

int			main(void)
{
	t_bal		bal;
	t_brick		brick;
	t_env		e;

	init_env(&e);
	ft_singleton(&e);
	init_val(&bal);
	e.map = get_map("level/level1.txt");
	e.curr_map = 1;
	init_window(&e);
	glfwSetKeyCallback(e.window, key_callback);
	glfwGetFramebufferSize(e.window, &e.width, &e.height);
	glClearColor(0.f, 0.f, 0.f, 0.0f);
	boucle_principal(&bal, &brick, &e);
	glfwTerminate();
	return (0);
}
