/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 15:54:10 by jfleisch          #+#    #+#             */
/*   Updated: 2018/08/08 15:54:11 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			hx(t_form *form, t_print *print, va_list vl)
{
	intmax_t	h;

	h = (unsigned char)va_arg(vl, intmax_t);
	print_flags(form, print, 0, ft_ultoa_base(h, 16));
	ft_putstr(ft_ultoa_base(h, 16));
	print->loc += ft_strlen(ft_ultoa_base(h, 16));
	print_flags_back(form, print, 0, ft_ultoa_base(h, 16));
}

void			lx(t_form *form, t_print *print, va_list vl)
{
	unsigned long long l;

	l = va_arg(vl, unsigned long long);
	print_flags(form, print, 0, ft_ultoa_base(l, 16));
	ft_putstr(ft_ultoa_base(l, 16));
	print->loc += ft_strlen(ft_ultoa_base(l, 16));
	print_flags_back(form, print, 0, ft_ultoa_base(l, 16));
}

void			jzx(t_form *form, t_print *print, va_list vl)
{
	intmax_t	jz;

	jz = (size_t)va_arg(vl, intmax_t);
	print_flags(form, print, 0, ft_ultoa_base(jz, 16));
	ft_putstr(ft_ultoa_base(jz, 16));
	print->loc += ft_strlen(ft_ultoa_base(jz, 16));
	print_flags_back(form, print, 0, ft_ultoa_base(jz, 16));
}

void			reg_x(t_form *form, t_print *print, va_list vl)
{
	unsigned int	reg;
	char			*str;

	reg = va_arg(vl, long);
	str = ft_ltoa_base(reg, 16);
	if (print->precision == 1)
		print_just(form, print, reg, str);
	print_flags(form, print, 0, str);
	ft_putstr(str);
	print->loc += ft_strlen(str);
	print_flags_back(form, print, 0, str);
}

void			form_x(t_form *form, t_print *print, va_list vl)
{
	if (form->x == 1 && print->h_2 == 1)
		hx(form, print, vl);
	else if (form->x == 1 && (print->l_1 == 1 || print->l_2 == 1))
		lx(form, print, vl);
	else if (form->x == 1 && (print->z == 1 || print->j == 1))
		jzx(form, print, vl);
	else if (form->x == 1)
		reg_x(form, print, vl);
}
