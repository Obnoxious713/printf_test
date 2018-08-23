/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 13:08:55 by jfleisch          #+#    #+#             */
/*   Updated: 2018/02/20 13:08:57 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void				ft_putstr(char const *str)
{
	int				i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}
