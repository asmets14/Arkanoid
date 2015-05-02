#include "arkanoid.h"

void init_val(t_bal *bal)
{	
	bal->y1 = -0.87;
	bal->radius = 0.03;
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
}
