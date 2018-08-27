/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 15:11:21 by jfleisch          #+#    #+#             */
/*   Updated: 2018/02/21 15:11:46 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*fresh_string;

	if (!s1 || !s2)
		return (NULL);
	fresh_string = (char *)ft_memalloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (fresh_string == NULL)
		return (NULL);
	ft_strcpy(fresh_string, s1);
	ft_strcat(fresh_string, s2);
	return (fresh_string);
}
