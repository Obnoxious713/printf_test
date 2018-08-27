/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_x_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 15:54:10 by jfleisch          #+#    #+#             */
/*   Updated: 2018/08/08 15:54:11 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			hx_1(t_form *form, t_print *print, va_list vl)
{
	intmax_t	h;

	h = (unsigned char)va_arg(vl, intmax_t);
	print_flags(form, print, 0, ft_ultoa_base(h, 16));
	ft_putstr(ft_strtoupper(ft_ultoa_base(h, 16)));
	print->loc += ft_strlen(ft_ultoa_base(h, 16));
	print_flags_back(form, print, 0, ft_ultoa_base(h, 16));
}

void			lx_1(t_form *form, t_print *print, va_list vl)
{
	unsigned long long	l;

	l = va_arg(vl, unsigned long long);
	if (print->precision == 1)
		print_just(form, print, l, ft_ultoa_base(l, 16));
	print_flags(form, print, 0, ft_ultoa_base(l, 16));
	ft_putstr(ft_strtoupper(ft_ultoa_base(l, 16)));
	print->loc += ft_strlen(ft_ultoa_base(l, 16));
	print_flags_back(form, print, 0, ft_ultoa_base(l, 16));
}

void			jzx_1(t_form *form, t_print *print, va_list vl)
{
	intmax_t	jz;

	jz = (size_t)va_arg(vl, intmax_t);
	print_flags(form, print, 0, ft_ultoa_base(jz, 16));
	ft_putstr(ft_strtoupper(ft_ultoa_base(jz, 16)));
	print->loc += ft_strlen(ft_ultoa_base(jz, 16));
	print_flags_back(form, print, 0, ft_ultoa_base(jz, 16));
}

void			reg_x_1(t_form *form, t_print *print, va_list vl)
{
	unsigned int	reg;

	reg = va_arg(vl, long);
	if (print->precision == 1)
		print_just(form, print, reg, ft_ultoa_base(reg, 16));
	print_flags(form, print, 0, ft_ltoa_base(reg, 16));
	ft_putstr(ft_strtoupper(ft_ltoa_base(reg, 16)));
	print->loc += ft_strlen(ft_ltoa_base(reg, 16));
	print_flags_back(form, print, 0, ft_ltoa_base(reg, 16));
}

void			form_x_1(t_form *form, t_print *print, va_list vl)
{
	if (form->x_1 == 1 && print->h_2 == 1)
		hx_1(form, print, vl);
	else if (form->x_1 == 1 && (print->l_1 == 1 || print->l_2 == 1))
		lx_1(form, print, vl);
	else if (form->x_1 == 1 && (print->j == 1 || print->z == 1))
		jzx_1(form, print, vl);
	else if (form->x_1 == 1)
		reg_x_1(form, print, vl);
}
