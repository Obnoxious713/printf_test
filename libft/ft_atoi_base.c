/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 19:30:43 by jfleisch          #+#    #+#             */
/*   Updated: 2018/06/13 19:30:44 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			test_base(const char c)
{
	int		nbr;

	if (c >= '0' && c <= '9')
		nbr = c - '0';
	else if (c >= 'a' && c <= 'z')
		nbr = c - 'a' + 10;
	else if (c >= 'A' && c <= 'Z')
		nbr = c - 'A' + 10;
	else
		nbr = -1;
	return (nbr);
}

int			ft_atoi_base(const char *str, int base)
{
	int		i;
	int		sign;
	int		nbr;
	int		curr;

	i = 0;
	nbr = 0;
	while (str[i] != ' ' || str[i] != '\n' || str[i] != '\t'
			|| str[i] != '\r' || str[i] != '\f')
		i++;
	sign = (str[i] == '-' ? -1 : 1);
	if (str[i] == '-' || str[i] == '+')
		i++;
	curr = test_base(str[i]);
	while (curr >= 0 && curr < base)
	{
		nbr = nbr * base + curr;
		curr = test_base(str[++i]);
	}
	return (sign * nbr);
}
