#define GLFW_INCLUDE_GLU

#include "./glfw/include/GLFW/glfw3.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>
#include "./libft/libft.h"

#define SPEED 0.02
typedef struct s_bal
{
	float	x2;
	float	y2;
	float 	x1;
	float	y1;
	double	radius;
	int		dir_x;
	int		dir_y;
	float	angle;
}				t_bal;

GLFWwindow *window;
int width;
int height;
float x_bar;
int 	space;
int 	pauz;

void key_callback( GLFWwindow* window, int key, int scancode, int action, int mods )
{
	(void)mods;
	(void)scancode;
	if(key == 80 && action == GLFW_PRESS)
		pauz *= -1;
	if (key == 32 && action == GLFW_PRESS)
		space = 1;
	if (key == 263 && (action == GLFW_REPEAT || action == GLFW_PRESS) && x_bar > -1)
	{
		if(pauz == 1)
		x_bar -= 0.024;
	}
	if (key == 262 && (action == GLFW_REPEAT || action == GLFW_PRESS) && x_bar < 0.75)
	{
		if(pauz == 1)
		x_bar += 0.024;
	}
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GL_TRUE);
		exit(1);
	}
}

void get_color(char nb)
{
	if(nb == '1')
	{
		glColor3f(1.f, 0.f, 0.f);
	}
	else if(nb == '2')
	{
		glColor3f(0.f, 1.f, 0.f);
	}
	else if(nb == '3')
	{
		glColor3f(0.f, 0.f, 1.f);
	}
	else if(nb == '4')
	{
		glColor3f(0.5f, 0.5f, 0.5f);
	}
}
void draw_bricks(char **map)
{
	float x;
	float y;
	float tx;
	float ty;
	int i;
	int j;

	i = 0;
	x = -0.99;
	y = 0.9;
	tx = 0.189;
	ty = -0.08;
	while(map[i])
	{
		x = -0.99;
		j = 0;
		while(map[i][j])
		{
			if (map[i][j] != '0')
			{
				glBegin(GL_POLYGON);
				get_color(map[i][j]);
				glVertex2f(x, y);
				get_color(map[i][j]);
				glVertex2f(x + tx, y);
				get_color(map[i][j]);
				glVertex2f(x + tx, y + ty);
				get_color(map[i][j]);
				glVertex2f(x, y + ty);
				glEnd();
			}
			x += tx + 0.01;
			j++;
		}
		y += ty - 0.01;
		i++;
	}
}

char **get_map()
{
	int fd;
	int ret;
	char buf[89];
	U2JhXHKv
	fd = open("level/level1.txt", O_RDONLY);
	ret = read(fd, buf, 88);
	buf[ret] = '\0';
	return (ft_strsplit(buf, '\n'));
}

void draw_circle(t_bal *bal)
{

	float	angle;
	 
	glColor3f(0.2, 0.9, 0.6);
	 
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(bal->x1, bal->y1);
	for(angle = 0.0f; angle <= 2 * M_PI; angle += 0.005)
	{
	    bal->x2 = bal->x1 + sin(angle) * bal->radius;
	    bal->y2 = bal->y1 + cos(angle) * bal->radius;
	    glVertex2f(bal->x2, bal->y2);
	}
	glEnd();
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

void move_bal(t_bal *bal)
{
	//srand(time(NULL));
	// bal->angle = (rand() % (10 + 1));

	if(bal->x1 < -1.0 || bal->x1 > 1.0)
	{
		bal->dir_x *= -1;
	}
	if(bal->y1 < -1.0 || bal->y1 > 1.0)
	{
		bal->dir_y *= -1;
	}
	
	bal->x1 += (SPEED * bal->dir_x);
	bal->y1 += (SPEED * bal->dir_y);
}

int main (void)
{
//	int		posX;
//	int		posY;
	char	**map;
	t_bal	bal;

/* ------------- INIT BALLE -------------*/
	bal.y1 = -0.87;
	bal.radius = 0.03;

	space = 0;
	bal.dir_x = 1;
	bal.dir_y = 1;
	pauz = 1;
	map = get_map();
	width = 1200;
	height = 1200;
	x_bar = 0;
	if (!glfwInit())
		exit(2);
	if (!(window = glfwCreateWindow(width, height, "Arkanoid", NULL, NULL)))
	{
		glfwTerminate();
		exit( EXIT_FAILURE );
	}
	glfwSetKeyCallback(window, key_callback);
	glfwGetFramebufferSize(window, &width, &height); // recupere valeur en pixels du framebuffer
	glClearColor( 0.f, 0.f, 0.f, 0.0f );

	while (1)
	{
		if (glfwWindowShouldClose(window))
			break;
		glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
		draw_bricks(map);
		if (space == 0)
			bal.x1 = x_bar + 0.125;
		draw_circle(&bal); // radius x y
		draw_barre(x_bar, -0.90);
		if(space == 1 && pauz == 1)
		{
			move_bal(&bal);
		}
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
	return (0);
}

































