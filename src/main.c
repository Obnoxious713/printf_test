/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 14:57:27 by jfleisch          #+#    #+#             */
/*   Updated: 2018/08/08 14:57:29 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libpf/include/libpf.h"

void			display_usage(char *av)
{
	ft_putendl("usage: ");
	ft_putstr(av);
	ft_putendl(" format <ARGS>");
	exit(1);
}

int				main(int ac, char **av)
{
	if (ac == 2)
		ft_printf(av[1]);
	else
		display_usage(av[0]);
	return (0);
}
