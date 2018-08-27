/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 13:09:06 by jfleisch          #+#    #+#             */
/*   Updated: 2018/05/30 13:09:08 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

int					read_next(char **arr, char **line)
{
	char			*tmp;
	char			*line_read;

	tmp = ft_strchr(*arr, '\n');
	if (**arr == '\0')
		return (0);
	if (tmp)
	{
		*tmp = '\0';
		*line = ft_strdup(*arr);
		line_read = ft_strdup(ft_strchr(*arr, '\0') + 1);
		ft_memdel((void**)arr);
		*arr = line_read;
	}
	else
	{
		*line = ft_strdup(*arr);
		ft_memdel((void**)arr);
	}
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	static char		*str[FD_MAX];
	int				rd;
	char			buf[BUFF_SIZE + 1];
	char			*ret;

	if (fd < 0 || line == NULL || read(fd, buf, 0) < 0)
		return (-1);
	if (str[fd] == NULL)
		str[fd] = ft_strnew(0);
	while (!(ft_strchr(str[fd], '\n')))
	{
		rd = read(fd, buf, BUFF_SIZE);
		if (rd == 0)
			break ;
		else
			buf[rd] = '\0';
		ret = ft_strjoin(str[fd], buf);
		free(str[fd]);
		str[fd] = ret;
	}
	return (read_next(&str[fd], line));
}
