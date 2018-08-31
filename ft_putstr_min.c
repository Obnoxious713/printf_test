/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_min.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 13:03:37 by jfleisch          #+#    #+#             */
/*   Updated: 2018/08/31 13:03:39 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
