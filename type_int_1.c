/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_uint_oct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 16:45:14 by jfleisch          #+#    #+#             */
/*   Updated: 2018/09/01 16:45:15 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			type_o_1(t_type *type, t_print *print, va_list vlst)
{
	unsigned long long	o;

	o = va_arg(vlst, unsigned long long);
	if (print->precision == 1)
		print_prec(type, print, o, ft_ltoa_base(o, 8));
	print_flags_start(type, print, 0, ft_ltoa_base(o, 8));
	print->loc += ft_strlen(ft_ltoa_base(o, 8));
	ft_putstr(ft_strtoupper(ft_ltoa_base(o, 8)));
	print_flags_end(type, print, 0, ft_ltoa_base(o, 8));
}

void			type_o(t_type *type, t_print *print, va_list vlst)
{
	intmax_t			o;
	unsigned long long	l;

	if (type->o == 1 && print->h_2 == 1)
	{
		o = (unsigned char)va_arg(vlst, intmax_t);
		print_flags_start(type, print, 0, ft_itoa_base(o, 8));
		print->loc += ft_strlen(ft_itoa_base(o, 8));
		ft_putstr(ft_strtoupper(ft_itoa_base(o, 8)));
		print_flags_end(type, print, 0, ft_itoa_base(o, 8));
	}
	else if (type->o == 1)
	{
		l = va_arg(vlst, unsigned long long);
		if (print->precision == 1)
			print_prec(type, print, l, ft_ultoa_base(l, 8));
		print_flags_start(type, print, 0, ft_ultoa_base(l, 8));
		print->loc += ft_strlen(ft_ultoa_base(l, 8));
		ft_putstr(ft_ultoa_base(l, 8));
		print_flags_end(type, print, 0, ft_ultoa_base(l, 8));
	}
	if (type->o_1 == 1)
		type_o_1(type, print, vlst);
}

void			type_u(t_type *type, t_print *print, va_list vlst)
{
	intmax_t			u;
	unsigned long long	l;

	if (type->u == 1 && print->h_2 == 1)
	{
		u = (unsigned char)va_arg(vlst, intmax_t);
		ft_putnbr_pr(u, print);
	}
	else if (type->u == 1)
	{
		l = va_arg(vlst, unsigned long long);
		if (print->precision == 1)
			print_prec(type, print, l, NULL);
		ft_putulong(l, print);
	}
}

void			type_d_1(t_type *type, t_print *print, va_list vlst)
{
	long long	d;
	char		*str;

	if (type->d_1 == 1)
	{
		d = va_arg(vlst, long long);
		str = ft_ltoa_base(d, 10);
		print_flags_start(type, print, d, NULL);
		ft_putstr(str);
		print->loc += ft_strlen(str);
		print_flags_end(type, print, d, NULL);
	}
}

void			last_d(t_type *type, t_print *print, va_list vlst)
{
	intmax_t	d;

	d = (int)va_arg(vlst, intmax_t);
	print_flags_start(type, print, d, NULL);
	if (print->zero == 1 && d < 0)
		d *= -1;
	if (print->precision == 1)
	{
		print_prec(type, print, d, NULL);
		if (d < 0)
			d *= -1;
	}
	ft_putnbr_pr(d, print);
	print_flags_end(type, print, d, NULL);
}
