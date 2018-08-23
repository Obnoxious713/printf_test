/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 15:05:50 by jfleisch          #+#    #+#             */
/*   Updated: 2018/02/21 15:06:17 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char				*ft_strnew(size_t size)
{
	char			*str;

	str = ft_memalloc(size + 1);
	if (str)
		ft_bzero(str, size + 1);
	return (str);
}
