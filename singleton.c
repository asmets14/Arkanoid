#include "arkanoid.h"

t_env *ft_singleton(t_env *ptr)
{
	static t_env *save = NULL;

	if (ptr)
		save = ptr;
	return (save);
}