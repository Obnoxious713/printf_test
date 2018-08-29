/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flgas2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 15:54:10 by jfleisch          #+#    #+#             */
/*   Updated: 2018/08/08 15:54:11 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int				num_len(long num)
{
	int			i;

	i = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		num *= -1;
		i++;
	}
	while (num > 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

int				num_len_i(int num)
{
	int			i;

	i = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		num *= -1;
		i++;
	}
	while (num > 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

void			form_zed(t_form *form, int num, char *str)
{
	if (form->d == 1 || form->i == 1)
		form->len = num_len(num);
	else if (form->x == 1 || form->x_1 == 1 || form->s == 1)
		form->len = ft_strlen(str);
	else if (form->c == 1)
		form->len = 1;
	else if (form->p == 1)
		form->len = ft_strlen(str) + 2;
}

void			print_flags(t_form *form, t_print *print,
							long num, char *str)
{
	if (print->plus == 1)
		print_plus(form, print, num);
	if ((print->zed == 1 && print->minus == 0))
	{
		form_zed(form, num, str);
		if (num < 0)
		{
			ft_putchar('-');
			print->loc++;
		}
		if (print->before_len > 0 && print->after_len > 0)
			print_just(form, print, num, str);
		else
			print_zed(form, print);
	}
	if (print->space == 1)
		print_space(form, print, num);
	if (print->sharp == 1)
		print_sharp(form, print, str);
	if (print->zed == 1)
		print->precision = 0;
}

void			print_flags_back(t_form *form, t_print *print,
								long num, char *str)
{
	if (print->minus == 1)
	{
		if (form->d == 1 || form->i == 1)
		{
			if (print->l_1 == 1 || print->l_2 == 1)
				form->len = num_len(num);
			else
				form->len = num_len_i((int)num);
		}
		else if (form->x == 1 || form->x_1 == 1 || form->o == 1 ||
					form->o_1 == 1 || form->s == 1 || form->s_1 == 1)
			form_xo(form, print, str);
		else if (form->p == 1)
		{
			if (num == 0)
				form->len = 3;
			else
				form->len = ft_strlen(str) + 2;
		}
		else if (form->c == 1)
			form->len = 1;
		print_minus(form, print);
	}
}
