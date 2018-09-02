/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 15:01:47 by jfleisch          #+#    #+#             */
/*   Updated: 2018/08/31 15:01:48 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int				num_len_l(long num)
{
	int			i;

	i = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		num *= -1;
		i++;
	}
	while (num > 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

int				num_len_i(int num)
{
	int			i;

	i = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		num *= -1;
		i++;
	}
	while (num > 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

void			osx_len(t_type *type, t_print *print, char *str)
{
	if (print->before_len > 0 && print->after_size < (int)ft_strlen(str))
		type->len = print->after_size;
	else
		type->len = ft_strlen(str);
}

void			zero_len(t_type *type, int num, char *str)
{
	if (type->d == 1 || type->i == 1)
		type->len = num_len_l(num);
	else if (type->x == 1 || type->x_1 == 1 || type->s == 1)
		type->len = ft_strlen(str);
	else if (type->c == 1)
		type->len = 1;
	else if (type->p == 1)
		type->len = ft_strlen(str) + 2;
}
