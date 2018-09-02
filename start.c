/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 13:15:02 by jfleisch          #+#    #+#             */
/*   Updated: 2018/08/31 13:15:03 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			def_val2(t_print *print)
{
	print->size = 0;
	print->just_size = 0;
	print->percent = 0;
	print->before_size = 0;
	print->before_len = 0;
	print->after_size = 0;
	print->after_len = 0;
	print->precision = 0;
	print->space = 0;
}

void			def_val(t_print *print, t_type *type)
{
	print->plus = 0;
	print->minus = 0;
	print->sharp = 0;
	print->zero = 0;
	print->l_1 = 0;
	print->l_2 = 0;
	print->h_1 = 0;
	print->h_2 = 0;
	print->j = 0;
	print->z = 0;
	type->s = 0;
	type->s_1 = 0;
	type->p = 0;
	type->d = 0;
	type->d_1 = 0;
	type->i = 0;
	type->o = 0;
	type->o_1 = 0;
	type->u = 0;
	type->u_1 = 0;
	type->x = 0;
	type->x_1 = 0;
	type->c = 0;
	type->c_1 = 0;
	type->len = 0;
}

void			start(const char *format, t_type *type, t_print *print,
						va_list vlst)
{
	int			loc;

	loc = 0;
	while (format[loc])
	{
		loc = get_loc(format, loc, print);
		if (format[loc] == '\0')
			break ;
		while (format[loc])
		{
			loc = flag_loc(format, loc, print, type);
			if ((ft_isdigit(format[loc + 1]) && format[loc + 1] != '0') ||
					format[loc + 1] == '.')
				loc = parse_loc(format, loc, type, print);
			loc = size_loc(format, loc, print);
			loc = space_loc(format, loc, print);
			if (get_type(format, loc, type))
			{
				loc = parse_flag_loc(type, print, vlst, loc);
				break ;
			}
			loc = last_loc(format, loc, print);
		}
	}
}
