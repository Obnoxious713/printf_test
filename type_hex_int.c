/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint_hex_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 19:19:10 by jfleisch          #+#    #+#             */
/*   Updated: 2018/08/31 19:19:11 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			hx(t_type *type, t_print *print, va_list vlst)
{
	intmax_t	h;

	h = (unsigned char)va_arg(vlst, intmax_t);
	print_flags_start(type, print, 0, ft_ultoa_base(h, 16));
	ft_putstr(ft_ultoa_base(h, 16));
	print->loc += ft_strlen(ft_ultoa_base(h, 16));
	print_flags_end(type, print, 0, ft_ultoa_base(h, 16));
}

void			lx(t_type *type, t_print *print, va_list vlst)
{
	unsigned long long	l;

	l =va_arg(vlst, unsigned long long);
	print_flags_start(type, print, 0, ft_ultoa_base(l, 16));
	ft_putstr(ft_ultoa_base(l, 16));
	print->loc += ft_strlen(ft_ultoa_base(l, 16));
	print_flags_end(type, print, 0, ft_ultoa_base(l, 16));
}

void			jzx(t_type *type, t_print *print, va_list vlst)
{
	intmax_t	jz;

	jz = (size_t)va_arg(vlst, intmax_t);
	print_flags_start(type, print, 0, ft_ultoa_base(jz, 16));
	ft_putstr(ft_ultoa_base(jz, 16));
	print->loc += ft_strlen(ft_ultoa_base(jz, 16));
	print_flags_end(type, print, 0, ft_ultoa_base(jz, 16));
}

void			reg_x(t_type *type, t_print *print, va_list vlst)
{
	unsigned int	x;
	char			*str;

	x = va_arg(vlst, long);
	str = ft_ltoa_base(x, 16);
	if (print->precision == 1)
		print_prec(type, print, x, str);
	print_flags_start(type, print, 0, str);
	ft_putstr(str);
	print->loc += ft_strlen(str);
	print_flags_end(type, print, 0, str);
}

void			type_x(t_type *type, t_print *print, va_list vlst)
{
	if (type->x == 1 && print->h_2 == 1)
		hx(type, print, vlst);
	else if (type->x == 1 && (print->l_1 == 1 || print->l_2 == 1))
		lx(type, print, vlst);
	else if (type->x == 1 && (print->z == 1 || print->j == 1))
		jzx(type, print, vlst);
	else if (type->x == 1)
		reg_x(type, print, vlst);
}
