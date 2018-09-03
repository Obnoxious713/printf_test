/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_prec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 15:04:32 by jfleisch          #+#    #+#             */
/*   Updated: 2018/08/31 15:05:13 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			ft_putstr_prec(char *str, t_print *print)
{
	int			i;
	int			j;
	int			len;

	i = 0;
	j = 0;
	if (print->after_size < (int)ft_strlen(str))
		len = print->before_size - print->after_size;
	else
		len = print->before_size - (int)ft_strlen(str);
	while (j < len)
	{
		ft_putchar(' ');
		j++;
		print->loc++;
	}
	while (i < print->after_size)
	{
		if (!str[i])
			break ;
		ft_putchar(str[i]);
		i++;
		print->loc++;
	}
}

void			ft_putwstr_prec(wchar_t *str, t_print *print)
{
	int			i;
	int			j;
	int			len;

	i = 0;
	j = 0;
	if (print->after_size < ft_wstrlen(str))
		len = print->before_size - print->after_size;
	else
		len = print->before_size - ft_wstrlen(str);
	while (j < len)
	{
		ft_putchar(' ');
		j++;
		print->loc++;
	}
	while (i < print->after_size)
	{
		if (!str[i])
			break ;
		ft_putchar(str[i]);
		i++;
		print->loc++;
	}
}

void			ft_putnbr_pr(int num, t_print *print)
{
	int			min;

	min = 0;
	if (num < 0)
	{
		ft_putchar('-');
		print->loc++;
		if (num == -2147483648)
		{
			min = 1;
			num = 2147483647;
		}
		else
			num *= -1;
	}
	if (num >= 10)
		ft_putnbr_pr(num / 10, print);
	print->loc++;
	ft_putchar((num % 10 + min) + '0');
}

void			ft_putulong(unsigned long long n, t_print *print)
{
	int			i;
	int			tmp[100];

	i = 0;
	if (n == 0)
	{
		print->loc++;
		ft_putchar('0');
	}
	while (n > 0)
	{
		tmp[i] = n % 10;
		n /= 10;
		i++;
	}
	while (--i >= 0)
	{
		ft_putchar('0' + tmp[i]);
		print->loc++;
	}
}

void			ft_putstr_min(char *str, t_print *print)
{
	int			i;

	i = 0;
	while (i < print->after_size && str[i])
	{
		ft_putchar(str[i]);
		i++;
		print->loc++;
	}
}
