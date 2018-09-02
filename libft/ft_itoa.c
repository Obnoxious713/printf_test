/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 15:16:17 by jfleisch          #+#    #+#             */
/*   Updated: 2018/02/21 15:16:32 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		num_size(int n)
{
	int			i;

	if (n < 0)
		i = 3;
	else
		i = 2;
	while (n /= 10)
		i++;
	i--;
	return (i);
}

char			*ft_itoa(int n)
{
	int			size;
	int			neg;
	char		*str;
	char		*res;

	neg = 1;
	if (n == '\0')
		return ("0");
	size = num_size(n);
	str = ft_memalloc(size);
	if (n < 0)
		neg = -1;
	str[size--] = '\0';
	while (n)
	{
		str[size--] = neg * (n % 10) + '0';
		n /= 10;
	}
	if (neg == -1)
		str[size--] = '-';
	res = str;
	free(str);
	return (res);
}
