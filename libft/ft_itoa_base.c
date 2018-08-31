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

static int		get_len(int n, int base)
{
	int	i;

	i = 0;
	if (n < 0)
		i = 3;
	else
		i = 2;
	while ((n /= base))
		i++;
	i--;
	return (i);
}

char			*ft_itoa_base(int n, int base)
{
	char	*str;
	int		check;
	int		len;
	char	*checkbase;

	checkbase = (char*)ft_memalloc(17);
	checkbase = "0123456789abcdef";
	if (n == 0 || n == '\0')
		return ("0");
	check = 1;
	len = get_len(n, base);
	str = (char*)ft_memalloc(len);
	if (n < 0)
		check = -1;
	str[len--] = '\0';
	while (n)
	{
		str[len--] = checkbase[check * (n % base)];
		n /= base;
	}
	if (check == -1)
		str[len--] = '-';
	free(str);
	return (str);
}
