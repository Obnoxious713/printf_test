/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 15:54:10 by jfleisch          #+#    #+#             */
/*   Updated: 2018/08/08 15:54:11 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			ft_putstr_min(char *str, t_print *print)
{
	int			i;

	i = 0;
	while (i < print->after_size && str[i])
	{
		ft_putchar(str[i++]);
		print->loc++;
	}
}

void			form_s_1(t_form *form, t_print *print, va_list vl)
{
	int			i;
	wchar_t		*str;

	i = 0;
	str = va_arg(vl, wchar_t*);
	if (print->precision == 1)
	{
		ft_putwstr_prec(str, print);
		form->len = print->after_size;
	}
	else
	{
		while (str[i])
		{
			ft_putchar(str[i++]);
			print->loc++;
		}
		form->len = i;
	}
	if (print->minus == 1)
		print_minus(form, print);
}

void			form_s(t_form *form, t_print *print, va_list vl)
{
	char		*str;

	if (form->s == 1 && print->l_1 == 1)
		form_s_1(form, print, vl);
	else if (form->s == 1)
	{
		str = va_arg(vl, char*);
		if (str == 0)
			str = "(null)";
		print_flags(form, print, '\0', str);
		if (print->precision == 1)
			ft_putstr_prec(str, print);
		else if (print->minus == 1)
			ft_putstr_min(str, print);
		else
		{
			ft_putstr(str);
			print->loc += ft_strlen(str);
		}
		print_flags_back(form, print, 0, str);
	}
}

void			form_c(t_form *form, t_print *print, va_list vl)
{
	int			c;
	wchar_t		c_1;

	c = '\0';
	if (form->c == 1)
	{
		print_flags(form, print, c, NULL);
		c = va_arg(vl, int);
		if (print->precision == 1)
			print_just(form, print, c, NULL);
		ft_putchar(c);
		print->loc++;
		print_flags_back(form, print, c, NULL);
	}
	else if (form->c_1 == 1)
	{
		c_1 = va_arg(vl, wchar_t);
		ft_putchar(c_1);
		print->loc++;
		print_flags_back(form, print, c_1, NULL);
	}
}
