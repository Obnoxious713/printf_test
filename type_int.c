/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 15:30:55 by jfleisch          #+#    #+#             */
/*   Updated: 2018/08/31 15:30:56 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			ld(t_type *type, t_print *print, va_list vlst)
{
	long long	l;

	if ((type->d == 1 && (print->l_2 == 1 || print->l_1 == 1))
		|| (type->i == 1 && (print->l_2 == 1 || print->l_1)))
	{
		if (print->l_2 == 1)
			l = (long long)va_arg(vlst, intmax_t);
		else
			l = (long)va_arg(vlst, intmax_t);
		print_flags_start(type, print, l, NULL);
		if (print->zero == 1 && l < 0)
			l *= -1;
		ft_putstr(ft_ltoa_base(l, 10));
		print->loc += ft_strlen(ft_ltoa_base(l, 10));
		print_flags_end(type, print, l, NULL);
	}
}

void			hd(t_type *type, t_print *print, va_list vlst)
{
	intmax_t	h;

	h = (char)va_arg(vlst, int);
	print_flags_start(type, print, h, NULL);
	if (print->zero == 1 && h < 0)
		h *= -1;
	ft_putstr(ft_itoa(h));
	print->loc++;
	print_flags_end(type, print, h, NULL);
}

void			zd(t_type *type, t_print *print, va_list vlst)
{
	intmax_t	z;

	z = (size_t)va_arg(vlst, intmax_t);
	print_flags_start(type, print, z, NULL);
	if (print->zero == 1 && z < 0)
		z *= -1;
	ft_putstr(ft_ltoa_base(z, 10));
	print->loc += ft_strlen(ft_ltoa_base(z, 10));
	print_flags_end(type, print, z, NULL);
}

void			jd(t_type *type, t_print *print, va_list vlst)
{
	intmax_t	j;

	j = va_arg(vlst, intmax_t);
	print_flags_start(type, print, j, NULL);
	if (print->zero == 1 && j < 0)
		j *= -1;
	ft_putstr(ft_ltoa_base(j, 10));
	print->loc += ft_strlen(ft_ltoa_base(j, 10));
	print_flags_end(type, print, j, NULL);
}

void			type_d(t_type *type, t_print *print, va_list vlst)
{
	if ((type->d == 1 && (print->l_2 == 1 || print->l_1 == 1)) ||
			(type->i == 1 && (print->l_2 == 1 || print->l_1 == 1)))
		ld(type, print, vlst);
	else if ((type->d == 1 && print->h_2 == 1)
			|| (type->i == 1 && print->h_2 == 1))
		hd(type, print, vlst);
	else if ((type->d == 1 && print->z == 1)
			|| (type->i == 1 && print->z == 1))
		zd(type, print, vlst);
	else if ((type->d == 1 && print->j == 1)
			|| (type->i == 1 && print->j == 1))
		jd(type, print, vlst);
	else if (type->d == 1 || type->i == 1)
		last_d(type, print, vlst);
}
