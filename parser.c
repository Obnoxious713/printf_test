/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 14:24:30 by jfleisch          #+#    #+#             */
/*   Updated: 2018/08/31 14:24:31 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int				parse_flag(const char *format, int loc, t_print *print)
{
	if (format[loc + 1] == '\0')
		return (0);
	else if (format[loc + 1] == '+')
		print->plus = 1;
	else if (format[loc + 1] == '-')
		print->minus = 1;
	else if (format[loc + 1] == '#')
		print->sharp = 1;
	else if (format[loc + 1] == '0')
		print->zero = 1;
	else
		return (0);
	return (1);
}

int				parse_just(const char *format, int loc, t_type *type,
						t_print *print)
{
	if (format[loc] != '.')
	{
		loc = get_tsize(format, loc, type, print);
		print->before_size = print->size;
		print->before_len = type->len;
	}
	if (format[loc + 1] == '.' || format[loc] == '.')
	{
		if (format[loc] == '.')
			loc++;
		else
			loc += 2;
		loc = get_tsize(format, loc, type, print);
		print->after_size = print->size;
		print->after_len = type->len;
	}
	if (print->minus != 1)
		print->precision = 1;
	if (print->plus == 1 || print->minus == 1 ||
			print->zero == 1 || print->sharp == 1)
		return (loc - 1);
	if (print->before_len == 0 && print->after_len == 0)
		return (loc + 2);
	return (loc);
}

int				parse_len(const char *format, int i, t_print *print)
{
	if (format[i + 1] == '\0')
		return (0);
	if (format[i + 1] == 'l' && format[i + 2] != 'l')
		print->l_1 = 1;
	else if (format[i + 1] == 'l' && format[i + 2] == 'l')
		print->l_2 = 1;
	if (format[i + 1] == 'h' && format[i + 2] != 'h')
		print->h_1 = 1;
	else if (format[i + 1] == 'h' && format[i + 2] == 'h')
		print->h_2 = 1;
	else if (format[i + 1] == 'j')
		print->j = 1;
	else if (format[i + 1] == 'z')
		print->z = 1;
	else
		return (0);
	return (1);
}
