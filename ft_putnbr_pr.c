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
			num = (int)2147483648;
		}
		else
			num *= -1;
	}
	if (num >= 10)
		ft_putnbr_pr(num / 10, print);
	print->loc++;
	ft_putchar(((num % 10) + min) + '0');
}
