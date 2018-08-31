/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 13:31:27 by jfleisch          #+#    #+#             */
/*   Updated: 2018/08/31 13:31:29 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int				get_loc(const char *format, int loc, t_print *print)
{
	while (format[loc])
	{
		if (format[loc] == '%')
		{
			if (format[loc + 1] == '%')
			{
				ft_putchar('%');
				print->loc++;
				loc++;
			}
			else
				return (loc);
		}
		else
		{
			ft_putchar(format[loc]);
			print->loc++;
		}
		loc++;
	}
	return (loc);
}

int				type_loc(const char *format, int loc,
							t_print *print, t_type *type)
{
	if (parse_flag(format, loc, print))
	{
		if (print->minus == 1 && print->zero == 0 &&
				print->sharp == 0 && print->plus == 0)
		{
			parse_just(format, loc, type, print);
			//todo rename ^
			loc = get_zsize(format, loc, print);
		}
		else if (print->zero == 1 && print->minus == 0 &&
			print->sharp == 0 && print->plus == 0)
		{
			parse_just(format, loc, type, print);
			loc = get_psize(format, loc, print);
			loc--;
		}
		else
			loc++;
	}
	return (loc);
}

int				size_loc(const char *format, int loc, t_print *print)
{
	if (parse_len(format, loc, print))
	{
		if (print->h_2 == 1 || print->l_2 == 1)
			loc += 2;
		else
			loc++;
	}
	return (loc);
}

int				space_loc(const char *format, int loc, t_print *print)
{
	if (format[loc + 1] == ' ' && format[loc] == '%')
		print->space = 1;
		// 	loc++;
	return (++loc);
}

int				last_loc(const char *format, int loc, t_print *print)
{
	if (!ft_isdigit(format[loc + 1]) && !parse_flag(format, loc, print) &&
			!parse_len(format, loc, print) && format[loc + 1] != '.')
		loc++;
	return (loc);
}
