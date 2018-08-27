/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 15:38:55 by jfleisch          #+#    #+#             */
/*   Updated: 2018/02/21 16:42:57 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	char	tmp;
	int		i;
	int		j;

	i = -1;
	j = ft_strlen(str);
	while (++i < --j)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
	}
	return (str);
}
