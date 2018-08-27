/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 18:41:59 by gwood             #+#    #+#             */
/*   Updated: 2018/06/11 16:38:19 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_listaddb(t_gnl *alst, t_gnl *new)
{
	if (alst != NULL && new != NULL)
	{
		alst->next = new;
		new->prev = alst;
	}
}

t_gnl		*ft_listnew(int fd)
{
	t_gnl *i;

	if (!(i = (t_gnl*)ft_memalloc(sizeof(t_gnl))))
		return (NULL);
	i->c = NULL;
	i->fd = fd;
	i->next = NULL;
	i->prev = NULL;
	return (i);
}

int			helper(char **line, t_gnl **buffsave)
{
	char			*e;
	t_gnl			*tmp;

	e = ft_strchr((*buffsave)->c, '\n');
	if (e != NULL)
	{
		*e = '\0';
		*line = ft_strdup((*buffsave)->c);
		(*buffsave)->c = ft_strcpy((*buffsave)->c, e + 1);
		return (1);
	}
	if (0 < ft_strlen(((*buffsave)->c)))
	{
		*line = ft_strdup(((*buffsave)->c));
		*(*buffsave)->c = '\0';
		return (1);
	}
	tmp = NULL;
	return (0);
}

t_gnl		*listfunction(t_gnl *buffsave, int fd)
{
	while ((int)buffsave->fd < fd && buffsave)
	{
		if (!buffsave->next)
			ft_listaddb(buffsave, ft_listnew(fd));
		buffsave = buffsave->next;
		if ((int)buffsave->fd == fd)
			return (buffsave);
	}
	while ((int)buffsave->fd > fd && buffsave)
	{
		buffsave = buffsave->prev;
		if ((int)buffsave->fd == fd)
			return (buffsave);
	}
	return (0);
}

int			ft_gnl(const int fd, char **line)
{
	static t_gnl	*buffsave;
	char			buf[BUFF_SIZE + 1];
	int				check;

	if (line == NULL || fd < 0 || BUFF_SIZE <= 0 || fd >= MAX_FD)
		return (-1);
	if (buffsave && (int)buffsave->fd != fd && fd)
		buffsave = listfunction(buffsave, fd);
	if (buffsave == NULL)
		buffsave = ft_listnew(fd);
	*line = 0;
	while ((check = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[check] = '\0';
		buffsave->c = ft_strjoinfree(buffsave->c, buf, 1);
		ft_bzero(buf, BUFF_SIZE + 1);
	}
	if (check < 0)
		return (-1);
	return (helper(line, &buffsave));
}
