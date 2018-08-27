/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 16:26:39 by jfleisch          #+#    #+#             */
/*   Updated: 2018/08/01 16:26:39 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strndup(const char *s, size_t n)
{
	char	*str;

	if (!(str = (char *)ft_memalloc(sizeof(char) * n + 1)))
		return (NULL);
	str = ft_strncpy(str, s, n);
	str[n] = 0;
	return (str);
}
