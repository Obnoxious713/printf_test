/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_extra_flags.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 15:54:10 by jfleisch          #+#    #+#             */
/*   Updated: 2018/08/08 15:54:11 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			print_plus(t_form *form, t_print *print, int num)
{
	if (form->d == 1 || form->d_1 == 1 || form->i == 1)
	{
		if (num >= 0)
		{
			ft_putchar('+');
			print->loc++;
		}
	}
}

void			print_minus(t_form *form, t_print *print)
{
	int			i;
	int			size;

	i = form->len;
	if (print->before_len > 0)
		size = print->before_size;
	else
		size = print->size;
	if (i > 0)
	{
		while (i < size)
		{
			ft_putchar(' ');
			i++;
			print->loc++;
		}
	}
}

void			print_zed(t_form *form, t_print *print)
{
	int			i;

	i = form->len;
	if (print->plus == 1)
		i++;
	while (i < print->size)
	{
		ft_putchar('0');
		i++;
		print->loc++;
	}
}

void			print_sharp(t_form *form, t_print *print, char *str)
{
	if ((form->x == 1 || form->x_1 == 1) && ft_atoi(str) > 0)
	{
		if (form->x == 1)
			ft_putstr("0x");
		else
			ft_putstr("0X");
		print->loc += 2;
	}
	else if (form->o == 1 || form->o_1 == 1)
	{
		if (ft_atoi(str) != 0)
		{
			print->loc++;
			ft_putchar('0');
		}
	}
}

void			print_space(t_form *form, t_print *print, long num)
{
	if (form->d == 1 || form->i == 1)
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
