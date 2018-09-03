/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 14:14:28 by jfleisch          #+#    #+#             */
/*   Updated: 2018/08/31 14:14:29 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			many_types(t_type *type, t_print *print, va_list vlst)
{
	type_d(type, print, vlst);
	type_d_1(type, print, vlst);
	type_c(type, print, vlst);
	type_s(type, print, vlst);
	type_x(type, print, vlst);
	type_x_1(type, print, vlst);
	type_o(type, print, vlst);
	type_p(type, print, vlst);
	type_u(type, print, vlst);
}

int				check_type(const char *format, int i)
{
	if (format[i + 1] == 'd' || format[i + 1] == 'D' ||
			format[i + 1] == 'c' || format[i + 1] == 'C' ||
			format[i + 1] == 's' || format[i + 1] == 'S' ||
			format[i + 1] == 'p' || format[i + 1] == 'i' ||
			format[i + 1] == 'o' || format[i + 1] == 'O' ||
			format[i + 1] == 'u' || format[i + 1] == 'U' ||
			format[i + 1] == 'x' || format[i + 1] == 'X')
		return (1);
	return (0);
}

int				get_percent(const char *format, int i)
{
	if (format[i] == '-' || format[i] == '+' || format[i] == '0' ||
		format[i] == '#' || format[i] == 'd' || format[i] == 'D' ||
		format[i] == 'c' || format[i] == 's' || format[i] == 'S' ||
		format[i] == 'p' || format[i] == 'i' || format[i] == 'o' ||
		format[i] == 'O' || format[i] == 'u' || format[i] == 'U' ||
		format[i] == 'x' || format[i] == 'X' || format[i] == 'C' ||
		format[i] == 'h' || format[i] == 'l' || format[i] == 'j' ||
		format[i] == 'z')
		return (1);
	return (0);
}

int				get_type2(const char *format, int i, t_type *type)
{
	if (format[i + 1] == '\0')
		return (0);
	else if (format[i + 1] == 'U')
		type->u_1 = 1;
	else if (format[i + 1] == 'x')
		type->x = 1;
	else if (format[i + 1] == 'X')
		type->x_1 = 1;
	else if (format[i + 1] == 'c')
		type->c = 1;
	else if (format[i + 1] == 'C')
		type->c_1 = 1;
	else
		return (0);
	return (1);
}

int				get_type(const char *format, int i, t_type *type)
{
	if (format[i + 1] == '\0')
		return (0);
	if (format[i + 1] == 's')
		type->s = 1;
	else if (format[i + 1] == 'S')
		type->s_1 = 1;
	else if (format[i + 1] == 'p')
		type->p = 1;
	else if (format[i + 1] == 'd')
		type->d = 1;
	else if (format[i + 1] == 'D')
		type->d_1 = 1;
	else if (format[i + 1] == 'i')
		type->i = 1;
	else if (format[i + 1] == 'o')
		type->o = 1;
	else if (format[i + 1] == 'O')
		type->o_1 = 1;
	else if (format[i + 1] == 'u')
		type->u = 1;
	else if (get_type2(format, i, type))
		type->u = type->u;
	else
		return (0);
	return (1);
}
