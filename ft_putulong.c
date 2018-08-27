/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 15:54:10 by jfleisch          #+#    #+#             */
/*   Updated: 2018/08/08 15:54:11 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			ft_putulong(t_print *print, unsigned long long n)
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
