#include "arkanoid.h"

static double		ft_sin2(double x, double my_sin)
{
	my_sin = 1.27323954 * x + .405284735 * x * x;
	if (my_sin < 0)
		my_sin = .225 * (my_sin *-my_sin - my_sin) + my_sin;
	else
		my_sin = .225 * (my_sin * my_sin - my_sin) + my_sin;
	return(my_sin);
}

double				ft_sin(double x)
{
	double my_sin;

	my_sin = 0;
	if (x < -3.14159265)
		x += 6.28318531;
	else
		if (x >  3.14159265)
			x -= 6.28318531;
	if (x < 0)
		my_sin = ft_sin2(x, my_sin);
	else
	{
		my_sin = 1.27323954 * x - 0.405284735 * x * x;
		if (my_sin < 0)
			my_sin = .225 * (my_sin *-my_sin - my_sin) + my_sin;
		else
			my_sin = .225 * (my_sin * my_sin - my_sin) + my_sin;
	}
	return(my_sin);
}

static double		ft_cos2(double x, double my_cos)
{
	my_cos = 1.27323954 * x + 0.405284735 * x * x;
	if (my_cos < 0)
		my_cos = .225 * (my_cos *-my_cos - my_cos) + my_cos;
	else
		my_cos = .225 * (my_cos * my_cos - my_cos) + my_cos;
	return(my_cos);
}

double				ft_cos(double x)
{
	double	my_cos;

	my_cos = 0;
	x += 1.57079632;
	if (x >  3.14159265)
		x -= 6.28318531;
	if (x < 0)
		my_cos = ft_cos2(x, my_cos);
	else
	{
		my_cos = 1.27323954 * x - 0.405284735 * x * x;
		if (my_cos < 0)
			my_cos = .225 * (my_cos *-my_cos - my_cos) + my_cos;
		else
			my_cos = .225 * (my_cos * my_cos - my_cos) + my_cos;
	}
	return(my_cos);
}

float				ft_sqrt2(const float n)
{
	float x = n;
	float y = 1;
	float e = 0.0000001; /* e decides the accuracy level*/
	
	while(x - y > e)
	{
		x = (x + y)/2;
		y = n/x;
	}
	return x;
}

void 				normalize(t_bal *bal)
{
	float tmp;

	tmp = ft_sqrt2(bal->dir_x * bal->dir_x *+ bal->dir_y * bal->dir_y);
	bal->norm_x = bal->dir_x / tmp;
	bal->norm_y = bal->dir_y / tmp;
}
