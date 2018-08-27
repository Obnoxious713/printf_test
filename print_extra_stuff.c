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

int				print_just_i(t_form *form, t_print *print,
								intmax_t num, char *str)
{
	int			i;

	if (form->d == 1 || form->i == 1 || form->u == 1)
		i = num_len(num);
	else if (form->c == 1)
		i = 1;
	else if (form->p == 1)
	{
		if (num == 0)
			i = 3;
		else
			i = ft_strlen(str) + 2;
	}
	else
		i = ft_strlen(str);
	if (print->space == 1 && print->after_len == 0)
		i++;
	if (num < 0 && (form->d == 1 || form->i == 1 || form->u == 1))
		i--;
	return (i);
}

void			print_space_min(int i, int z_len, intmax_t num, t_print *print)
{
	while (i < print->before_size - (z_len))
	{
		ft_putchar(' ');
		print->loc++;
		i++;
	}
	if (num < 0)
	{
		ft_putchar('-');
		print->loc++;
	}
}

void			print_just_zed(int y, int z_len, t_print *print)
{
	while (y < z_len)
	{
		ft_putchar('0');
		print->loc++;
		y++;
	}
}

void			print_just(t_form *form, t_print *print, intmax_t num,
								char *str)
{
	int			i;
	int			x;
	int			y;
	int			z_len;

	i = print_just_i(form, print, num, str);
	x = i;
	y = 0;
	z_len = print->after_size - x;
	if (z_len < 0)
		z_len = 0;
	if (num < 0)
		i++;
	print_space_min(i, z_len, num, print);
	if (form->p == 1)
	{
		ft_putstr("0x");
		if (print->after_size > x)
			z_len += 2;
	}
	print_just_zed(y, z_len, print);
}
