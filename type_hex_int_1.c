/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint_hex_x_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 19:19:17 by jfleisch          #+#    #+#             */
/*   Updated: 2018/08/31 19:19:18 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			hx_1(t_type *type, t_print *print, va_list vlst)
{
	intmax_t	h;

	h = (unsigned char)va_arg(vlst, intmax_t);
	print_flags_start(type, print, 0, ft_ultoa_base(h, 16));
	ft_putstr(ft_strtoupper(ft_ultoa_base(h, 16)));
	print->loc += ft_strlen(ft_ultoa_base(h, 16));
	print_flags_end(type, print, 0, ft_ultoa_base(h, 16));
}

void			lx_1(t_type *type, t_print *print, va_list vlst)
{
	unsigned long long	l;

	l = va_arg(vlst, unsigned long long);
	if (print->precision == 1)
		print_prec(type, print, l, ft_ultoa_base(l, 16));
	print_flags_start(type, print, 0, ft_ultoa_base(l, 16));
	ft_putstr(ft_strtoupper(ft_ultoa_base(l, 16)));
	print->loc += ft_strlen(ft_ultoa_base(l, 16));
	print_flags_end(type, print, 0, ft_ultoa_base(l, 16));
}

void			jzx_1(t_type *type, t_print *print, va_list vlst)
{
	intmax_t	jz;

	jz = (size_t)va_arg(vlst, intmax_t);
	print_flags_start(type, print, 0, ft_ultoa_base(jz, 16));
	ft_putstr(ft_strtoupper(ft_ultoa_base(jz, 16)));
	print->loc += ft_strlen(ft_ultoa_base(jz, 16));
	print_flags_end(type, print, 0, ft_ultoa_base(jz, 16));
}

void			reg_x_1(t_type *type, t_print *print, va_list vlst)
{
	unsigned int	reg;

	reg = va_arg(vlst, long);
	if (print->precision == 1)
		print_prec(type, print, reg, ft_ultoa_base(reg, 16));
	print_flags_start(type, print, 0, ft_ltoa_base(reg, 16));
	ft_putstr(ft_strtoupper(ft_ltoa_base(reg, 16)));
	print->loc += ft_strlen(ft_ltoa_base(reg, 16));
	print_flags_end(type, print, 0, ft_ltoa_base(reg, 16));
}

void			type_x_1(t_type *type, t_print *print, va_list vlst)
{
	if (type->x_1 == 1 && print->h_2 == 1)
		hx_1(type, print, vlst);
	else if (type->x_1 == 1 && (print->l_1 == 1 || print->l_2 == 1))
		lx_1(type, print, vlst);
	else if (type->x_1 == 1 && (print->z == 1 || print->j == 1))
		jzx_1(type, print, vlst);
	else if (type->x_1 == 1)
		reg_x_1(type, print, vlst);
}
