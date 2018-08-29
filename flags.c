/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flgas.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 15:54:10 by jfleisch          #+#    #+#             */
/*   Updated: 2018/08/08 15:54:11 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			form_d_1(t_form *form, t_print *print, va_list vl)
{
	long long	num_l;
	char		*str;

	if (form->d_1 == 1)
	{
		num_l = va_arg(vl, long long);
		str = ft_ltoa_base(num_l, 10);
		print_flags(form, print, num_l, NULL);
		ft_putstr(str);
		print->loc += ft_strlen(str);
		print_flags_back(form, print, num_l, NULL);
	}
}

void			ft_putstr_prec(char *str, t_print *print)
{
	int			i;
	int			j;
	int			len;

	i = -1;
	j = -1;
	if (print->after_size < (int)ft_strlen(str))
		len = print->before_size - print->after_size;
	else
		len = print->before_size - (int)ft_strlen(str);
	while (++j < len)
	{
		ft_putchar(' ');
		print->loc++;
	}
	while (++i < print->after_size)
	{
		if (!str[i])
			break ;
		ft_putchar(str[i]);
		print->loc++;
	}
}

int				ft_wstrlen(wchar_t *str)
{
	int			i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void			ft_putwstr_prec(wchar_t *str, t_print *print)
{
	int			i;
	int			j;
	int			len;

	i = -1;
	j = -1;
	if (print->after_size < ft_wstrlen(str))
		len = print->before_size - print->after_size;
	else
		len = print->before_size - ft_wstrlen(str);
	while (++j < len)
	{
		ft_putchar(' ');
		print->loc++;
	}
	while (++i < print->after_size)
	{
		if (!str[i])
			break ;
		ft_putchar(str[i]);
		print->loc++;
	}
}
