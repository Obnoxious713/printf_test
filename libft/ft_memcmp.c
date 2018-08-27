/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 14:52:44 by jfleisch          #+#    #+#             */
/*   Updated: 2018/03/08 17:52:16 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;
	unsigned char		c1;
	unsigned char		c2;

	if ((!s1 && !s2) || n == 0)
		return (0);
	p1 = (const unsigned char *)s1;
	p2 = (const unsigned char *)s2;
	c1 = *p1;
	c2 = *p2;
	while (c1 == c2 && n-- > 0)
	{
		c1 = *p1++;
		c2 = *p2++;
	}
	return (c1 - c2);
}
