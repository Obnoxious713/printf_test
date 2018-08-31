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
