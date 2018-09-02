/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr_prec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 15:05:34 by jfleisch          #+#    #+#             */
/*   Updated: 2018/08/31 15:05:35 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
