#ifndef ARKANOID
# define ARKANOID

#define GLFW_INCLUDE_GLU
#define SPEED 0.02

#include "./glfw/include/GLFW/glfw3.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>
#include "./libft/libft.h"

typedef struct  s_env
{
	GLFWwindow *window;
	int 		width;
	int 		height;
	float 		x_bar;
	int 		space;
	int 		pauz;
	char		**map;
}				t_env;

typedef struct	s_bal
{
	float		x2;
	float		y2;
	float 		x1;
	float		y1;
	double		radius;
	double 		norm_x;
	double 		norm_y;
	int			dir_x;
	int			dir_y;
	float		angle;
}				t_bal;

typedef struct 	s_brick
{
	float 		x;
	float 		y;
	float 		tx;
	float 		ty;
	int 		i;
	int 		j;
} 				t_brick;

typedef struct 	s_segment
{
    float      	x1;
    float      	y1;
    float      	x2;
    float      	y2;
}				t_segment;


typedef struct     s_seg
{
    t_segment    seg1;
    t_segment    seg2;
    t_segment    seg3;
    t_segment    seg4;
    t_segment    seg5;
    t_segment    seg6;
    t_segment    seg7;
    float        unite;
    float        dizaine;
}                t_seg;


void		init_val(t_bal *bal);
void		init_brick(t_brick *brick);
void		init_window(t_env *e);
void		draw_barre(float x, float y);
void		draw_circle(t_bal *bal);
void		draw_bricks(t_env *e, t_brick *brick);
void		get_color(char nb);
void		init_env(t_env *e);
double		ft_sin(double x);
double		ft_cos(double x);
float       ft_sqrt2(const float n);
void		normalize(t_bal *bal);
void 		move_ball(t_bal *bal, t_env *e);
void 		draw_centaine(t_seg *s);
void 		draw_dizaine(t_seg *s);
void 		draw_unite(t_seg *s);
void		draw_seg(t_seg *s);
void		init_seg2(t_seg *s);
void 		init_seg(t_seg *s);
void		key_callback( GLFWwindow *window, int key,
			int scancode, int action, int mods);
t_env		*ft_singleton(t_env *ptr);
void		move_bal(t_bal *bal, t_env *e);
#endif
