/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 14:51:41 by jfleisch          #+#    #+#             */
/*   Updated: 2018/02/21 14:52:02 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*d;
	unsigned char		*tmp;
	const unsigned char	*s;

	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	if ((tmp = (unsigned char *)ft_memalloc(sizeof(unsigned char) * len)))
	{
		i = -1;
		while (++i < len)
			tmp[i] = s[i];
		i = -1;
		while (++i < len)
			d[i] = tmp[i];
	}
	return (dst);
}
