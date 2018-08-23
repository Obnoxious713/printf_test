/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 15:54:10 by jfleisch          #+#    #+#             */
/*   Updated: 2018/08/08 15:54:11 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libpf/include/libpf.h"

void			ld(t_form *form, t_print *print, va_list vl)
{
	long long	l;

	if ((form->d == 1 && (print->l_2 == 1 || print->l_1 == 1))
			|| (form->i == 1 && (print->l_2 == 1 || print->l_1)))
	{
		if (print->l_2 == 1)
			l = (long long)va_arg(vl, intmax_t);
		else
			l = (long)va_arg(vl, intmax_t);
		print_flags(form, print, l, NULL);
		if (print->zed == 1 && l < 0)
			l *= -1;
		ft_putstr(ft_ltoa_base(l, 10));
		print->loc += ft_strlen(ft_ltoa_base(l, 10));
		print_flags_back(form, print, l, NULL);
	}
}

void			hd(t_form *form, t_print *print, va_list vl)
{
	intmax_t	h;

	h = (char)va_arg(vl, int);
	print_flags(form, print, h, NULL);
	if (print->zed == 1 && h < 0)
		h *= -1;
	ft_putstr(ft_itoa(h));
	print->loc += ft_strlen(ft_itoa(h));
	print_flags_back(form, print, h, NULL);
}

void			zd(t_form *form, t_print *print, va_list vl)
{
	intmax_t	z;

	z = (size_t)va_arg(vl, intmax_t);
	print_flags(form, print, z, NULL);
	if (print->zed == 1 && z < 0)
		z *= -1;
	ft_putstr(ft_ltoa_base(z, 10));
	print->loc += ft_strlen(ft_ltoa_base(z, 10));
	print_flags_back(form, print, z, NULL);
}

void			jd(t_form *form, t_print *print, va_list vl)
{
	intmax_t	j;

	j = va_arg(vl, intmax_t);
	print_flags(form, print, j, NULL);
	if (print->zed == 1 && j < 0)
		j *= -1;
	ft_putstr(ft_ltoa_base(j, 10));
	print->loc += ft_strlen(ft_ltoa_base(j, 10));
	print_flags_back(form, print, j, NULL);
}

void			form_d(t_form *form, t_print *print, va_list vl)
{
	if ((form->d == 1 && (print->l_2 == 1 || print->l_1 == 1))
			|| (form->i == 1 && (print->l_2 == 1 || print->l_1 == 1)))
		ld(form, print, vl);
	else if ((form->d == 1 && print->h_2 == 1)
			|| (form->i == 1 && print->h_2 == 1))
		hd(form, print, vl);
	else if ((form->d == 1 && print->z == 1)
			|| (form->i == 1 && print->z == 1))
		zd(form, print, vl);
	else if ((form->d == 1 && print->j == 1)
			|| (form->i == 1 && print->j == 1))
		jd(form, print, vl);
	else if (form->d == 1 || form->i == 1)
		last_d(form, print, vl);
}
