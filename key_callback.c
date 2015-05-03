#include "arkanoid.h"

static void esc( GLFWwindow *window)
{
		glfwSetWindowShouldClose(window, GL_TRUE);
		exit(1);
}

void key_callback( GLFWwindow *window, int key, int scancode, int action, int mods)
{
	t_env *e;

	e = ft_singleton(NULL);
	(void)mods;
	(void)scancode;
	if(key == 80 && action == GLFW_PRESS)
		e->pauz *= -1;
	if (key == 32 && action == GLFW_PRESS)
		e->space = 1;
	if (key == 263 && (action == GLFW_REPEAT ||
		action == GLFW_PRESS) && e->x_bar > -1)
	{
		if(e->pauz == 1)
		e->x_bar -= 0.04;
	}
	if (key == 262 && (action == GLFW_REPEAT ||
		action == GLFW_PRESS) && e->x_bar < 0.75)
	{
		if(e->pauz == 1)
		e->x_bar += 0.04;
	}
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		esc(window);
}