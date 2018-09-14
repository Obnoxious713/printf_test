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

#include "libftprintf.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>

int				main(void)
{
	////
	ft_putendl("\n\nd");
	ft_printf("\n%d", 42);
	ft_printf("\nKashim a %d histoires à raconter", 1001);
	ft_printf("\nIl fait au moins %d\n", -8000);
	ft_printf("\n%d", -0);
	ft_printf("\n%d", 0);
	ft_printf("\n%d", INT_MAX);
	ft_printf("\n%d", INT_MIN);
	ft_printf("\n%d", INT_MIN - 1);
	ft_printf("\n%d", INT_MAX + 1);
	ft_printf("\n%%d 0000042 == |%d|\n", 0000042);
	ft_printf("\n%%d \t == |%d|\n", '\t');
	ft_printf("\n%%d Lydie == |%d|\n", 'L'+'y'+'d'+'i'+'e');

	//
	ft_putendl("\n\ni");
	ft_printf("\n%i", 42);
	ft_printf("\nKashim a %i histoires à raconter", 1001);
	ft_printf("\nIl fait au moins %i\n", -8000);
	ft_printf("\n%i", -0);
	ft_printf("\n%i", 0);
	ft_printf("\n%i", INT_MAX);
	ft_printf("\n%i", INT_MIN);
	ft_printf("\n%i", INT_MIN - 1);
	ft_printf("\n%i", INT_MAX + 1);
	ft_printf("\n%%i 0000042 == |%i|\n", 0000042);
	ft_printf("\n%%i \t == |%i|\n", '\t');
	ft_printf("\n%%i Lydie == |%i|\n", 'L'+'y'+'d'+'i'+'e');
	//
	ft_putendl("\n\nminus");
	ft_printf("%%-i 42 == %-i\n", 42); //!
	ft_putendl("\n\\");
	ft_printf("%%-d 42 == %-d\n", INT_MIN); //!
	ft_putendl("\n\\");
	ft_printf("%%-i -42 == %-i\n", -42); //!
	ft_putendl("\n\\");
	//* probably not handling if there is no number after the minus
	ft_printf("\n%%-4d 42 == |%-4d|\n", 42);
	ft_putendl("\n\\");
	ft_printf("\n%%-5d -42 == |%-5d|\n", -42);
	ft_putendl("\n\\");
	ft_printf("\n|%3i|%-3i|\n", 42, 42);
	ft_putendl("\n\\");
	ft_printf("\n%%-4i 42 == |%-4i|\n", 42);
	// ////

	ft_putendl("\n\nminuspf");
	printf("\n%%-i 42 == %-i\n", 42); //!
	ft_putendl("\n\\");
	printf("\n%%-d 42 == %-d\n", INT_MIN); //!
	ft_putendl("\n\\");
	printf("\n%%-i -42 == %-i\n", -42); //!
	ft_putendl("\n\\");
	printf("\n%%-4d 42 == |%-4d|\n", 42);
	ft_putendl("\n\\");
	printf("\n%%-5d -42 == |%-5d|\n", -42);
	ft_putendl("\n\\");
	printf("\n|%3i|%-3i|\n", 42, 42);
	ft_putendl("\n\\");
	printf("\n%%-4i 42 == |%-4i|\n", 42);

	//? bonus
	// ft_putendl("\n\nstar");
	// // ft_printf("\n%%-*.3s LYDI == |%-*.3s|\n", 5, "LYDI"); //!
	// // ft_putendl("\n\\");
	// ft_printf("\n%% *.5i 42 == |% *.5i|\n", 4, 42);
	// ft_putendl("\n\\");
	// ft_printf("\n%%*i 42 == |%*i|\n", 5, 42);
	// ft_putendl("\n\\");
	// ft_printf("\n%%*i 42 == |%*i|\n", 3, 42);
	// ft_putendl("\n\\");
	// ft_printf("\n%%*i 42 == |%*i|\n", 2, 42);
	////
	return (0);
}
