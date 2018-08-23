/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_num_form.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 15:54:10 by jfleisch          #+#    #+#             */
/*   Updated: 2018/08/08 15:54:11 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libpf/include/libpf.h"

void			many_formats(t_form *form, t_print *print, va_list vl)
{
	form_d(form, print, vl);
	form_d_1(form, print, vl);
	form_c(form, print, vl);
	form_s(form, print, vl);
	form_x(form, print, vl);
	form_x_1(form, print, vl);
	form_o(form, print, vl);
	form_p(form, print, vl);
	form_u(form, print, vl);
}

int				check_form(const char *format, int i)
{
	if (format[i] == 'd' || format[i] == 'D' || format[i] == 'c' ||
			format[i] == 'C' || format[i] == 's' || format[i] == 'S' ||
			format[i] == 'p' || format[i] == 'i' || format[i] == 'o' ||
			format[i] == 'O' || format[i] == 'u' || format[i] == 'U' ||
			format[i] == 'x' || format[i] == 'X')
		return (1);
	return (0);
}

int				get_perc(const char *format, int i)
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
