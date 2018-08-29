/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 15:32:27 by jfleisch          #+#    #+#             */
/*   Updated: 2018/08/23 13:49:02 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int				get_loc(const char *format, int i, t_print *print)
{
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '%')
			{
				ft_putchar('%');
				print->loc++;
				i += 1;
			}
			else
				return (i);
		}
		else
		{
			ft_putchar(format[i]);
			print->loc++;
		}
		i++;
	}
	return (i);
}

int				parser(const char *format, t_form *form, t_print *print,
							va_list vl)
{
	int			i;

	i = 0;
	while (format[i])
	{
		i = get_loc(format, i, print);
		if (format[i] == '\0')
			break ;
		while (format[i])
		{
			i = parse_flag_i(format, i, print, form);
			if ((ft_isdigit(format[i + 1]) && format[i + 1] != '0')
					|| format[i + 1] == '.')
				i = parse_just(format, i, form, print);
			i = parse_size_i(format, i, print);
			i = space_i(format, i, print);
			if (parse_form(format, i, form))
			{
				i = parse_form_i(form, print, vl, i);
				break ;
			}
			i = last_i(format, i, print);
		}
	}
	return (0);
}

void			def_val2(t_print *print)
{
	print->size = 0;
	print->just_size = 0;
	print->perc = 0;
	print->before_size = 0;
	print->before_len = 0;
	print->after_size = 0;
	print->after_len = 0;
	print->precision = 0;
	print->space = 0;
}

void			def_val(t_print *print, t_form *form)
{
	print->plus = 0;
	print->minus = 0;
	print->sharp = 0;
	print->zed = 0;
	print->l_1 = 0;
	print->l_2 = 0;
	print->h_1 = 0;
	print->h_2 = 0;
	print->j = 0;
	print->z = 0;
	form->s = 0;
	form->s_1 = 0;
	form->p = 0;
	form->d = 0;
	form->d_1 = 0;
	form->i = 0;
	form->o = 0;
	form->o_1 = 0;
	form->u = 0;
	form->u_1 = 0;
	form->x = 0;
	form->x_1 = 0;
	form->c = 0;
	form->c_1 = 0;
	form->len = 0;
}

int				ft_printf(char *format, ...)
{
	va_list		vl;
	t_print		print;
	t_form		form;

	form.c = 0;
	print.loc = 0;
	def_val(&print, &form);
	def_val2(&print);
	va_start(vl, format);
	parser(format, &form, &print, vl);
	va_end(vl);
	def_val(&print, &form);
	def_val2(&print);
	return (print.loc);
}
