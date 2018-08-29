/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_po.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 15:54:10 by jfleisch          #+#    #+#             */
/*   Updated: 2018/08/08 15:54:11 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			form_o_1(t_form *form, t_print *print, va_list vl)
{
	unsigned long long	n;

	n = va_arg(vl, unsigned long long);
	if (print->precision == 1)
		print_just(form, print, n, ft_ltoa_base(n, 8));
	print_flags(form, print, 0, ft_ltoa_base(n, 8));
	print->loc += ft_strlen(ft_ltoa_base(n, 8));
	ft_putstr(ft_strtoupper(ft_ltoa_base(n, 8)));
	print_flags_back(form, print, 0, ft_ltoa_base(n, 8));
}

void			form_o(t_form *form, t_print *print, va_list vl)
{
	intmax_t			i;
	unsigned long long	l;

	if (form->o == 1 && print->h_2 == 1)
	{
		i = (unsigned char)va_arg(vl, intmax_t);
		print_flags(form, print, 0, ft_itoa_base(i, 8));
		print->loc += ft_strlen(ft_itoa_base(i, 8));
		ft_putstr(ft_strtoupper(ft_itoa_base(i, 8)));
		print_flags_back(form, print, 0, ft_itoa_base(i, 8));
	}
	else if (form->o == 1)
	{
		l = va_arg(vl, unsigned long long);
		if (print->precision == 1)
			print_just(form, print, l, ft_ultoa_base(l, 8));
		print_flags(form, print, 0, ft_ultoa_base(l, 8));
		print->loc += ft_strlen(ft_ultoa_base(l, 8));
		ft_putstr(ft_ultoa_base(l, 8));
		print_flags_back(form, print, 0, ft_ultoa_base(l, 8));
	}
	if (form->o_1 == 1)
		form_o_1(form, print, vl);
}

void			form_p(t_form *form, t_print *print, va_list vl)
{
	unsigned long long l;

	if (form->p == 1)
	{
		l = va_arg(vl, unsigned long long);
		if (print->precision == 1)
			print_just(form, print, l, ft_ltoa_base(l, 16));
		else
			ft_putstr("0x");
		if (l == 0)
			ft_putchar('0');
		else
			ft_putstr(ft_ltoa_base(l, 16));
		print->loc += ft_strlen(ft_ltoa_base(l, 16)) + 2;
		print_flags_back(form, print, l, ft_ltoa_base(l, 16));
	}
}

void			form_u(t_form *form, t_print *print, va_list vl)
{
	intmax_t			i;
	unsigned long long	l;

	if (form->u == 1 && print->h_2 == 1)
	{
		i = (unsigned char)va_arg(vl, intmax_t);
		ft_putnbr_pr(i, print);
	}
	else if (form->u == 1)
	{
		l = va_arg(vl, unsigned long long);
		if (print->precision == 1)
			print_just(form, print, l, NULL);
		ft_putulong(print, l);
	}
}

void			form_xo(t_form *form, t_print *print, char *str)
{
	if (print->before_len > 0 && print->after_size < (int)ft_strlen(str))
		form->len = print->after_size;
	else
		form->len = ft_strlen(str);
}
