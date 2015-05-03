#include "arkanoid.h"

void get_color(char nb)
{
	if(nb == '1')
		glColor3f(1.f, 0.f, 0.f);
	else if(nb == '2')
		glColor3f(0.f, 1.f, 0.f);
	else if(nb == '3')
		glColor3f(0.f, 0.f, 1.f);
	else if(nb == '4')
		glColor3f(0.5f, 0.5f, 0.5f);
}

void	draw_barre(float x, float y)
{
	float tx;
	float ty;

	tx = 0.25;
	ty = -0.05;
		glBegin(GL_POLYGON);
		glColor3f(0.1f, 0.5f, 0.5f);	
		glVertex2f(x, y);
		glColor3f(0.5f, 0.8f, 0.5f);
		glVertex2f(x + tx, y);
		glColor3f(0.5f, 0.5f, 0.99f);
		glVertex2f(x + tx, y + ty);
		glColor3f(0.12f, 0.5f, 0.5f);
		glVertex2f(x, y + ty);
		glEnd();
}

void draw_circle(t_bal *bal)
{

	float	angle;
	 
	glColor3f(0.2, 0.9, 0.6);
	 
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(bal->x1, bal->y1);
	for(angle = 0.0f; angle <= 2 * M_PI; angle += 0.005)
	{
	    bal->x2 = bal->x1 + ft_sin(angle) * bal->radius;
	    bal->y2 = bal->y1 + ft_cos(angle) * bal->radius;
	    glVertex2f(bal->x2, bal->y2);
	}
	glEnd();
}

void draw_bricks(char **map, t_brick *brick)
{
	init_brick(brick);
	while(map[brick->i])
	{
		brick->x = -0.99;
		brick->j = 0;
		while(map[brick->i][brick->j])
		{
			if (map[brick->i][brick->j] != '0')
			{
				glBegin(GL_POLYGON);
				get_color(map[brick->i][brick->j]);
				glVertex2f(brick->x, brick->y);
				get_color(map[brick->i][brick->j]);
				glVertex2f(brick->x + brick->tx, brick->y);
				get_color(map[brick->i][brick->j]);
				glVertex2f(brick->x + brick->tx, brick->y + brick->ty);
				get_color(map[brick->i][brick->j]);
				glVertex2f(brick->x, brick->y + brick->ty);
				glEnd();
			}
			brick->x += brick->tx + 0.01;
			brick->j++;
		}
		brick->y += brick->ty - 0.01;
		brick->i++;
	}
}
