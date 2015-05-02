/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarraul <gbarraul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 08:26:34 by gbarraul          #+#    #+#             */
/*   Updated: 2015/02/11 14:04:09 by asmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_lstcat(t_list *a)
{
	size_t	len;
	t_list	*b;
	char	*new;

	len = 0;
	b = a;
	while (b != NULL)
	{
		len += b->content_size - 1;
		b = b->next;
	}
	if ((new = (char *)malloc(sizeof(*new) * (len + 1))) == NULL)
		return (NULL);
	ft_bzero((void *)new, len + 1);
	while (a != NULL)
	{
		ft_strcat(new, a->content);
		a = a->next;
	}
	return (new);
}

static int		ft_remain(char **keep, t_list **lst, char **line)
{
	char	*s;

	if (*keep == NULL)
		return (0);
	s = *keep;
	while (*s != '\0' && *s != '\n')
		s++;
	if (*s == '\n')
	{
		*s = '\0';
		*line = *keep;
		if (*(s + 1) != '\0')
		{
			if ((*keep = ft_strdup(s + 1)) == NULL)
				return (-1);
		}
		else
			*keep = NULL;
		return (1);
	}
	if ((*lst = ft_lstnew((void *)*keep, ft_strlen(*keep) + 1)) == NULL)
		return (-1);
	ft_memdel((void **)keep);
	return (0);
}

static int		ft_readbuf(char *buf, char **keep, t_list **lst, char **line)
{
	char	*s;
	t_list	*new;

	s = buf;
	while (*s != '\0' && *s != '\n')
		s++;
	if (*s == '\n')
	{
		*s = '\0';
		if (!(new = ft_lstnew((void *)buf, ft_strlen(buf) + 1)))
			return (-1);
		ft_lstaddend(lst, new);
		*line = ft_lstcat(*lst);
		if (*(s + 1) != '\0')
		{
			*keep = ft_strdup(s + 1);
		}
		return (1);
	}
	if (!(new = ft_lstnew((void *)buf, ft_strlen(buf) + 1)))
		return (-1);
	ft_lstaddend(lst, new);
	return (0);
}

static void		ft_end(t_list **lst)
{
	t_list		*tmp;

	while (*lst)
	{
		ft_memdel(&((*lst)->content));
		tmp = (*lst)->next;
		ft_memdel((void **)lst);
		*lst = tmp;
	}
}

int				get_next_line(int const fd, char **line)
{
	static char		*keep[256];
	char			buf[BUFF_SIZE + 1];
	ssize_t			ret;
	t_list			*lst;

	if (line == NULL || fd < 0 || BUFF_SIZE <= 0)
		return (-1);
	lst = NULL;
	if ((ret = ft_remain(&keep[fd], &lst, line)) != 0)
		return (ret);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		*(buf + ret) = '\0';
		if ((ret = ft_readbuf(buf, &keep[fd], &lst, line)) != 0)
			return (ft_end(&lst), ret);
	}
	if (ret == -1)
		return (ft_end(&lst), -1);
	if (lst)
	{
		*line = ft_lstcat(lst);
		return (ft_end(&lst), 1);
	}
	*line = NULL;
	return (ft_end(&lst), 0);
}
