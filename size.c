/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 14:44:28 by jfleisch          #+#    #+#             */
/*   Updated: 2018/08/31 14:44:29 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int				get_tsize(const char *format, int loc,
						t_type *type, t_print *print)
{
	int			i;
	char		str[40];

	i = 0;
	if (!ft_isdigit(format[loc]))
	{
		if (get_percent(format, loc + 1))
			return (loc + 1);
		while (format[loc] && !ft_isdigit(format[loc]) &&
				format[loc] != '.')
			loc++;
	}
	while (ft_isdigit(format[loc]) && format[loc])
		str[i++] = format[loc++];
	str[i] = '\0';
	print->size = ft_atoi(str);
	type->len = i;
	if (print->sharp == 0 && print->plus == 0 &&
			print->minus == 0 && print->zero == 0)
		loc--;
	return (loc);
}

int				get_psize(const char *format, int loc, t_print *print)
{
	int			i;
	char		str[40];

	i = 0;
	if (!ft_isdigit(format[loc]))
	{
		if (get_percent(format, loc + 1) && format[loc + 1] != '-' &&
				format[loc + 1] != '0')
			return (loc + 1);
		while (format[loc] && !ft_isdigit(format[loc]))
			loc++;
	}
	while (ft_isdigit(format[loc]) && format[loc])
		str[i++] = format[loc++];
	str[i] = '\0';
	print->size = ft_atoi(str);
	if (print->sharp == 0 && print->plus == 0 &&
			print->minus == 0 && print->zero == 0)
		loc--;
	return (loc);
}

int				get_zsize(const char *format, int loc, t_print *print)
{
	int			i;
	char		str[40];

	i = 0;
	while (!ft_isdigit(format[loc]) && format[loc])
	{
		if (check_type(format, loc))
			return (loc);
		loc++;
	}
	while (ft_isdigit(format[loc]))
		str[i++] = format[loc++];
	print->size = ft_atoi(str);
	loc--;
	return (loc);
}
