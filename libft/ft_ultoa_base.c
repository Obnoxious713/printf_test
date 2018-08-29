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

static int		get_len(long long n, int base)
{
	int	i;

	i = 2;
	while (n /= base)
		i++;
	i--;
	return (i);
}

static char		*get_str(unsigned long long n, int base)
{
	int		k;
	char	*str;
	char	checkbase[16];
	char	*res;

	ft_strcpy(checkbase, "0123456789abcdef\0");
	k = get_len(n, base);
	str = (char*)ft_memalloc(200);
	if (str == NULL)
		return (NULL);
	str[k--] = '\0';
	while (n)
	{
		str[k--] = checkbase[n % base];
		n /= base;
	}
	res = str;
	free(str);
	return (res);
}

char			*ft_ultoa_base(unsigned long long n, int base)
{
	char	*str;

	if (n == 0)
		return ("0");
	str = get_str(n, base);
	return (str);
}
