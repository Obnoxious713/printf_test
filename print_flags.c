/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 19:12:09 by jfleisch          #+#    #+#             */
/*   Updated: 2018/08/31 19:12:10 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			print_plus(t_type *type, t_print *print, int num)
{
	if (type->d == 1 || type->d_1 == 1 || type->i == 1)
	{
		if (num >= 0)
		{
			ft_putchar('+');
			print->loc++;
		}
	}
}

void			print_minus(t_type *type, t_print *print)
{
	int			i;
	int			size;

	i = type->len;
	if (print->before_len > 0)
		size = print->before_size;
	else
		size = print->size;
	while (i < size)
	{
		ft_putchar(' ');
		i++;
		print->loc++;
	}
}

void			print_zero(t_type *type, t_print *print)
{
	int			i;

	i = type->len;
	if (print->plus == 1)
		i++;
	while (i < print->size)
	{
		ft_putchar('0');
		i++;
		print->loc++;
	}
}

void			print_sharp(t_type *type, t_print *print, char *str)
{
	if ((type->x == 1 || type->x_1 == 1) && ft_atoi(str) > 0)
	{
		if (type->x == 1)
			ft_putstr("0x");
		else
			ft_putstr("0X");
		print->loc += 2;
	}
	else if (type->o == 1 || type->o_1 == 1)
	{
		if (ft_atoi(str) != 0)
		{
			print->loc++;
			ft_putchar('0');
		}
	}
}

void			print_space(t_type *type, t_print *print, long num)
{
	if (type->d == 1 || type->i == 1)
	{
		if (num >= 0)
		{
			ft_putchar(' ');
			print->loc++;
		}
	}
	else
	{
		ft_putchar(' ');
		print->loc++;
	}
}
