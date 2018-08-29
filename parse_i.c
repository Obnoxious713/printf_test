/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_i.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 15:54:10 by jfleisch          #+#    #+#             */
/*   Updated: 2018/08/08 15:54:11 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int				parse_flag_i(const char *format, int i,
								t_print *print, t_form *form)
{
	if (parse_flag(format, i, print))
	{
		if (print->minus == 1 && print->zed == 0 &&
				print->sharp == 0 && print->plus == 0)
		{
			parse_just(format, i, form, print);
			i = size_zed(format, i, print);
		}
		else if (print->zed == 1 && print->minus == 0 &&
			print->sharp == 0 && print->plus == 0)
		{
			parse_just(format, i, form, print);
			i = get_size2(format, i, print);
			i--;
		}
		else
			i++;
	}
	return (i);
}

int				parse_size_i(const char *format, int i, t_print *print)
{
	if (parse_size(format, i, print))
	{
		if (print->h_2 == 1 || print->l_2 == 1)
			i += 2;
		else
			i++;
	}
	return (i);
}

int				parse_form_i(t_form *form, t_print *print, va_list vl, int i)
{
	many_formats(form, print, vl);
	def_val(print, form);
	def_val2(print);
	i += 2;
	return (i);
}

int				space_i(const char *format, int i, t_print *print)
{
	if (format[i + 1] == ' ' && format[i] == '%')
	{
		print->space = 1;
		i++;
	}
	return (i);
}

int				last_i(const char *format, int i, t_print *print)
{
	if (!ft_isdigit(format[i + 1]) && !parse_flag(format, i, print)	&&
			!parse_size(format, i, print) && format[i + 1] != '.')
		i++;
	return (i);
}
