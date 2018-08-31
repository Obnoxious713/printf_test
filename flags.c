/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 15:08:14 by jfleisch          #+#    #+#             */
/*   Updated: 2018/08/31 15:08:14 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			print_flags(t_type *type, t_print *print,
							long num, char *str)
{
	if (print->plus == 1)
		print_plus(type, print, num);
	if (print->zero == 1 && print->minus == 0)
	{
		zero_len(type, num, str);
		if (num < 0)
		{
			ft_putchar('-');
			print->loc++;
		}
		if (print->before_len > 0 && print->after_len > 0)
			print_just(type, print, num, str);
		else
			print_zero(type, print);
	}
	if (print->space == 1)
		print_space(type, print, num);
	if (print->sharp == 1)
		print_sharp(type, print, str);
	if (print->zero == 1)
		print->precision = 0;
}

void			print_flags_back(t_type *type, t_print *print,
								long num, char *str)
{
	if (print->minus == 1)
	{
		if (type->d == 1 || type->i == 1)
		{
			if (print->l_1 == 1 || print->l_2 == 1)
				type->len = num_len_l(num);
			else
				type->len = num_len_i((int)num);
		}
		else if (type->x == 1 || type->x_1 == 1 || type->o == 1 ||
					type->o_1 == 1 || type->s == 1 || type->s_1 == 1)
			type_xo(type, print, str);
			//todo rename ^
		else if (type->p == 1)
		{
			if (num == 0)
				type->len = 3;
			else
				type->len = ft_strlen(str) + 2;
		}
		else if (type->c == 1)
			type->len =1;
		print_minus(type, print);
	}
}
