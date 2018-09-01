/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 18:55:08 by jfleisch          #+#    #+#             */
/*   Updated: 2018/08/31 18:55:14 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			type_s_1(t_type *type, t_print *print, va_list vlst)
{
	int			i;
	wchar_t		*str;

	i = 0;
	str = va_arg(vlst, wchar_t*);
	if (print->precision == 1)
	{
		ft_putwstr_prec(str, print);
		type->len = print->after_size;
	}
	else
	{
		while (str[i])
		{
			ft_putchar(str[i++]);
			print->loc++;
		}
		type->len = i;
	}
	if (print->minus == 1)
		print_minus(type, print);
}

void			type_s(t_type *type, t_print *print, va_list vlst)
{
	char		*str;

	if (type->s == 1 && print->l_1 == 1)
		type_s_1(type, print, vlst);
	else if (type->s == 1)
	{
		str = va_arg(vlst, char*);
		if (str == 0)
			str = "(null)";
		print_flags_start(type, print, '\0', str);
		if (print->precision == 1)
			ft_putstr_prec(str, print);
		else if (print->minus)
			ft_putstr_min(str, print);
		else
		{
			ft_putstr(str);
			print->loc += ft_strlen(str);
		}
		print_flags_end(type, print, 0, str);
	}
}

void			type_c(t_type *type, t_print *print, va_list vlst)
{
	int			c;
	wchar_t		c_1;

	c = '\0';
	if (type->c == 1)
	{
		print_flags_start(type, print, c, NULL);
		c = va_arg(vlst, int);
		if (print->precision == 1)
			print_prec(type, print, c, NULL);
		ft_putchar(c);
		print->loc++;
		print_flags_end(type, print, c, NULL);
	}
	else if (type->c_1 == 1)
	{
		c_1 = va_arg(vlst, wchar_t);
		ft_putchar(c_1);
		print->loc++;
		print_flags_end(type, print, c_1, NULL);
	}
}
