/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 19:46:47 by jfleisch          #+#    #+#             */
/*   Updated: 2018/08/31 19:46:55 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int				prec_len(t_type *type, t_print *print,
							intmax_t num, char *str)
{
	int			len;

	if (type->d == 1 || type->i == 1 || type->u == 1)
		len = num_len_l(num);
	else if (type->c == 1)
		len = 1;
	else if (type->p == 1)
	{
		if (num == 0)
			len = 3;
		else
			len = ft_strlen(str) + 2;
	}
	else
		len = ft_strlen(str);
	if (print->space == 1 && print->after_len == 0)
		len++;
	if (num < 0 && (type->d == 1 || type->i == 1 || type->u == 1))
		len--;
	return (len);
}

void			print_zero_prec(int z_len, t_print *print)
{
	while (z_len--)
	{
		ft_putchar('0');
		print->loc++;
	}
}

void			print_space_prec(int loc, int z_len, t_print *print)
{
	while (loc++ < print->before_size - z_len)
	{
		ft_putchar(' ');
		print->loc++;
	}
}

void			print_prec(t_type *type, t_print *print,
								intmax_t num, char *str)
{
	int			loc;
	int			i;
	int			z_len;

	loc = prec_len(type, print, num, str);
	i = loc;
	z_len = print->after_size - i;
	if (z_len < 0)
		z_len = 0;
	if (num < 0)
		loc++;
	print_space_prec(loc, z_len, print);
	if (num < 0)
	{
		ft_putchar('-');
		print->loc++;
	}
	if (type->p == 1)
	{
		ft_putstr("0x");
		if (print->after_size > i)
			z_len = 2;
	}
	print_zero_prec(z_len, print);
}
