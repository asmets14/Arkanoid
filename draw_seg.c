/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_seg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvagner <rvagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 19:50:13 by rvagner           #+#    #+#             */
/*   Updated: 2015/05/03 20:01:17 by rvagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

void		draw_nb(t_seg *s, char nb, float add)
{
	glBegin(GL_LINES);
	ft_color_seg(nb, 2);
	glVertex2f(s->seg2.x1 + add, s->seg2.y1);
	glVertex2f(s->seg2.x2 + add, s->seg2.y2);
	ft_color_seg(nb, 4);
	glVertex2f(s->seg4.x1 + add, s->seg4.y1);
	glVertex2f(s->seg4.x2 + add, s->seg4.y2);
	ft_color_seg(nb, 7);
	glVertex2f(s->seg7.x1 + add, s->seg7.y1);
	glVertex2f(s->seg7.x2 + add, s->seg7.y2);
	ft_color_seg(nb, 1);
	glVertex2f(s->seg1.x1 + add, s->seg1.y1);
	glVertex2f(s->seg1.x2 + add, s->seg1.y2);
	ft_color_seg(nb, 5);
	glVertex2f(s->seg5.x1 + add, s->seg5.y1);
	glVertex2f(s->seg5.x2 + add, s->seg5.y2);
	ft_color_seg(nb, 3);
	glVertex2f(s->seg3.x1 + add, s->seg3.y1);
	glVertex2f(s->seg3.x2 + add, s->seg3.y2);
	ft_color_seg(nb, 6);
	glVertex2f(s->seg6.x1 + add, s->seg6.y1);
	glVertex2f(s->seg6.x2 + add, s->seg6.y2);
	glEnd();
}

char		*check_score(char *score, int ret)
{
	char	new_score[4];

	if (ret == 2)
	{
		new_score[0] = '0';
		new_score[1] = score[0];
		new_score[2] = score[1];
		new_score[3] = 0;
	}
	else if (ret == 1)
	{
		new_score[0] = '0';
		new_score[1] = '0';
		new_score[2] = score[0];
		new_score[3] = 0;
	}
	else
	{
		new_score[0] = score[0];
		new_score[1] = score[1];
		new_score[2] = score[2];
		new_score[3] = 0;
	}
	return (ft_strdup(new_score));
}

void		draw_seg(t_seg *s, t_env *e)
{
	char	*score;
	char	*new_score;

	score = ft_itoa(e->score);
	new_score = check_score(score, ft_strlen(score));
	glLineWidth (0.5);
	init_seg(s);
	draw_nb(s, new_score[0], 0.0);
	draw_nb(s, new_score[1], s->dizaine);
	draw_nb(s, new_score[2], s->unite);
}
