/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 15:54:10 by jfleisch          #+#    #+#             */
/*   Updated: 2018/08/08 15:54:11 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			parse_flag(const char *format, int i, t_print *print)
{
	if (format[i + 1] == '\0')
		return (0);
	if (format[i + 1] == '+')
		print->plus = 1;
	else if (format[i + 1] == '-')
		print->minus = 1;
	else if (format[i + 1] == '#')
		print->sharp = 1;
	else if (format[i + 1] == '0')
		print->zed = 1;
	else
		return (0);
	return (1);
}

int			parse_just(const char *format, int i, t_form *form, t_print *print)
{
	if (format[i] != '.')
	{
		i = size(format, i, form, print);
		print->before_size = print->size;
		print->before_len = form->len;
	}
	if (format[i + 1] == '.' || format[i] == '.')
	{
		if (format[i] == '.')
			i++;
		else
			i += 2;
		i = size(format, i, form, print);
		print->after_size = print->size;
		print->after_len = form->len;
	}
	if (print->minus != 1)
		print->precision = 1;
	if (print->plus == 1 || print->minus == 1
		|| print->zed == 1 || print->sharp == 1)
		return (i - 1);
	if (print->before_len == 0 && print->after_len == 0)
		return (i + 2);
	return (i);
}

int			parse_size(const char *format, int i, t_print *print)
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

int			parse_form2(const char *format, int i, t_form *form)
{
	if (format[i + 1] == '\0')
		return (0);
	if (format[i + 1] == 'u')
		form->u = 1;
	else if (format[i + 1] == 'U')
		form->u_1 = 1;
	else if (format[i + 1] == 'x')
		form->x = 1;
	else if (format[i + 1] == 'X')
		form->x_1 = 1;
	else if (format[i + 1] == 'c')
		form->c = 1;
	else if (format[i + 1] == 'C')
		form->c_1 = 1;
	else
		return (0);
	return (1);
}

int			parse_form(const char *format, int i, t_form *form)
{
	if (format[i + 1] == '\0')
		return (0);
	if (format[i + 1] == 's')
		form->s = 1;
	else if (format[i + 1] == 'S')
		form->s_1 = 1;
	else if (format[i + 1] == 'p')
		form->p = 1;
	else if (format[i + 1] == 'd')
		form->d = 1;
	else if (format[i + 1] == 'D')
		form->d_1 = 1;
	else if (format[i + 1] == 'i')
		form->i = 1;
	else if (format[i + 1] == 'o')
		form->o = 1;
	else if (format[i + 1] == 'O')
		form->o_1 = 1;
	else if (parse_form2(format, i, form))
		form->u = form->u;
	else
		return (0);
	return (1);
}
