#include "libft.h"

void	*ft_xmalloc(size_t size)
{
	void *new;

	new = malloc(size);
	if(!new)
		exit (1);
	else
		return(new);
}
