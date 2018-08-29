/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_i.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 15:54:10 by jfleisch          #+#    #+#             */
/*   Updated: 2018/08/08 15:54:11 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			last_d(t_form *form, t_print *print, va_list vl)
{
	intmax_t	inum;

	inum = (int)va_arg(vl, intmax_t);
	print_flags(form, print, inum, NULL);
	if (print->zed == 1 && inum < 0)
		inum *= -1;
	if (print->precision == 1)
	{
		print_just(form, print, inum, NULL);
		if (inum < 0)
			inum *= -1;
	}
	ft_putnbr_pr(inum, print);
	print_flags_back(form, print, inum, NULL);
}

int				get_size(const char *format, int i,
						t_form *form, t_print *print)
{
	int			j;
	char		str[40];

	j = 0;
	if (!ft_isdigit(format[i]))
	{
		if (get_perc(format, i + 1))
			return (i + 1);
		while (format[i] && !ft_isdigit(format[i]) && format[i] != '.')
			i++;
	}
	while (ft_isdigit(format[i]) && format[i])
	{
		str[j] = format[i];
		i++;
		j++;
	}
	str[j] = '\0';
	print->size = ft_atoi(str);
	form->len = j;
	if (print->sharp == 0 && print->plus == 0 &&
			print->minus == 0 && print->zed == 0)
		i--;
	return (i);
}

int				get_size2(const char *format, int i, t_print *print)
{
	int			j;
	char		str[40];

	j = 0;
	if (!ft_isdigit(format[i]))
	{
		if (get_perc(format, i + 1) && format[i + 1] != '-' &&
						format[i + 1] != '0')
			return (i + 1);
		while (format[i] && !ft_isdigit(format[i]))
			i++;
	}
	while (ft_isdigit(format[i]) && format[i])
	{
		str[j] = format[i];
		i++;
		j++;
	}
	str[j] = '\0';
	print->size = ft_atoi(str);
	if (print->sharp == 0 && print->plus == 0 &&
			print->minus == 0 && print->zed == 0)
		i--;
	return (i);
}

int				size_zed(const char *format, int i, t_print *print)
{
	int			size;
	char		str[40];

	size = 0;
	while (!ft_isdigit(format[i]) && format[i])
	{
		if (check_form(format, i))
			return (i);
		i++;
	}
	while (ft_isdigit(format[i]))
	{
		str[size] = format[i];
		size++;
		i++;
	}
	print->size = ft_atoi(str);
	i--;
	return (i);
}
