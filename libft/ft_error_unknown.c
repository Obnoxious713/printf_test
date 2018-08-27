/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_unknown.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 17:32:24 by jfleisch          #+#    #+#             */
/*   Updated: 2018/07/21 17:32:25 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <string.h>
#include <errno.h>

void	ft_error_unknown(void)
{
	ft_putstr("Error: ");
	ft_error(strerror(errno));
}
