#include "arkanoid.h"

#define SPEED 0.02

t_env *ft_singleton(t_env *ptr)
{
	static t_env *save = NULL;

	if (ptr)
		save = ptr;
	return (save);
}

void key_callback( GLFWwindow* window, int key, int scancode, int action, int mods)
{
	t_env *e;

	e = ft_singleton(NULL);
	(void)mods;
	(void)scancode;
	if(key == 80 && action == GLFW_PRESS)
		e->pauz *= -1;
	if (key == 32 && action == GLFW_PRESS)
		e->space = 1;
	if (key == 263 && (action == GLFW_REPEAT || action == GLFW_PRESS) && e->x_bar > -1)
	{
		if(e->pauz == 1)
		e->x_bar -= 0.024;
	}
	if (key == 262 && (action == GLFW_REPEAT || action == GLFW_PRESS) && e->x_bar < 0.75)
	{
		if(e->pauz == 1)
		e->x_bar += 0.024;
	}
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GL_TRUE);
		exit(1);
	}
}

char **get_map()
{
	int fd;
	int ret;
	char buf[89];
	fd = open("level/level1.txt", O_RDONLY);
	ret = read(fd, buf, 88);
	buf[ret] = '\0';
	return (ft_strsplit(buf, '\n'));
}




void move_bal(t_bal *bal, t_env *e)
{
	if(bal->x1 < -1.0 || bal->x1 > 1.0) // coter
		bal->dir_x *= -1;
	if(bal->y1 >= 1) // plafond
		bal->dir_y *= -1;
	if(bal->y1 <= -0.90 && (bal->x1 >= e->x_bar && bal->x1 <= (e->x_bar + 0.189))) // Detection palet!
	{
		bal->dir_y *= -1;
	}
	else if(bal->y1 < -1) // ta perdu
	{
		printf("Tu as perdu! Soit On relance [reset] Soit on quitte\n");
		sleep(5);
		exit(2);
	}
	bal->x1 += (SPEED * bal->dir_x);
	bal->y1 += (SPEED * bal->dir_y);
}



void boucle_principal(char **map, t_bal *bal, t_brick *brick, t_env *e)
{
	while(1)
	{
		if (glfwWindowShouldClose(e->window))
			break;
		glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
		draw_bricks(map, brick);
		if (e->space == 0)
			bal->x1 = e->x_bar + 0.125;
		draw_circle(bal); // radius x y
		draw_barre(e->x_bar, -0.90);
		if(e->space == 1 && e->pauz == 1)
		{
			move_bal(bal, e);
		}
		glfwSwapBuffers(e->window);
		glfwPollEvents();
	}
	
}

int main (void)
{
	char	**map;
	t_bal	bal;
	t_brick	brick;
	t_env 	e;

	init_env(&e);
	ft_singleton(&e);
	init_val(&bal);
	map = get_map();
	if (!glfwInit())
		exit(2);
	if (!(e.window = glfwCreateWindow(e.width, e.height, "Arkanoid", NULL, NULL)))
	{
		glfwTerminate();
		exit( EXIT_FAILURE );
	}
	glfwSetKeyCallback(e.window, key_callback);
	glfwGetFramebufferSize(e.window, &e.width, &e.height); // recupere valeur en pixels du framebuffer
	glClearColor( 0.f, 0.f, 0.f, 0.0f );
	boucle_principal(map, &bal, &brick, &e);
	glfwTerminate();
	return (0);
}

































