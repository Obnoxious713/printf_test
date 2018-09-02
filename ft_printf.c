/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 13:06:15 by jfleisch          #+#    #+#             */
/*   Updated: 2018/08/31 13:06:16 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int				ft_printf(const char *format, ...)
{
	va_list		vlstst;
	t_print		print;
	t_type		type;

	type.c = 0;
	print.loc = 0;
	def_val(&print, &type);
	def_val2(&print);
	va_start(vlstst, format);
	start(format, &type, &print, vlstst);
	va_end(vlstst);
	def_val(&print, &type);
	def_val2(&print);
	return (print.loc);
}
