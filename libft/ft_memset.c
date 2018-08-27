/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 14:45:45 by jfleisch          #+#    #+#             */
/*   Updated: 2018/02/21 14:47:22 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	ch;
	unsigned char	*p;

	i = -1;
	ch = (unsigned char)c;
	p = (unsigned char *)b;
	while (++i < len)
		p[i] = ch;
	return (b);
}
