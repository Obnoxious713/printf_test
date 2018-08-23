/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libpf.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 14:57:34 by jfleisch          #+#    #+#             */
/*   Updated: 2018/08/23 13:48:33 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPF_H
# define LIBPF_H

/*
** ------ LIBRARIES ------
*/
# include "../../libft/include/libft.h"
# include <stdarg.h>

/*
** ------ TYPEDEFS ------
*/
typedef struct	s_form
{
	int			s;
	int			s_1;
	int			p;
	int			d;
	int			d_1;
	int			i;
	int			o;
	int			o_1;
	int			u;
	int			u_1;
	int			x;
	int			x_1;
	int			c;
	int			c_1;
	int			len;
}				t_form;

typedef struct	s_print
{
	int			cap;
	int			plus;
	int			minus;
	int			sharp;
	int			zed;
	int			l_1;
	int			l_2;
	int			h_1;
	int			h_2;
	int			j;
	int			z;
	int			loc;
	int			size;
	int			just_size;
	int			perc;
	int			before_size;
	int			after_size;
	int			before_len;
	int			after_len;
	int			precision;
	int			space;
}				t_print;

/*
** ------ FUNCTIONS ------
*/
int				ft_printf(char *format, ...);
void			def_val(t_print *print, t_form *form);
void			def_val2(t_print *print);
int				parser(const char *format, t_form *form, t_print *print,
							va_list vl);
int				get_loc(const char *format, int i, t_print *print);
int				parse_flag(const char *format, int i, t_print *print);
int				parse_just(const char *format, int i, t_form *form,
							t_print *print);
int				parse_size(const char *format, int i, t_print *print);
int				parse_form2(const char *format, int i, t_form *form);
int				parse_form(const char *format, int i, t_form *form);
void			form_d_1(t_form *form, t_print *print, va_list vl);
void			ft_putstr_prec(char *str, t_print *print);
int				ft_wstrlen(wchar_t *str);
void			ft_putwstr_prec(wchar_t *str, t_print *print);
int				num_len(long num);
void			form_len(t_form *form, int num, char *str);
void			print_flags(t_form *form, t_print *print, long num,
								char *str);
void			print_flags_back(t_form *form, t_print *print, long num,
									char *str);
void			ft_putnbr_pr(int num, t_print *print);
void			ft_putulong(t_print *print, unsigned long long n);
void			ft_putstr_min(char *str, t_print *print);
void			form_s_1(t_form *form, t_print *print, va_list vl);
void			form_s(t_form *form, t_print *print, va_list vl);
void			form_c(t_form *form, t_print *print, va_list vl);
int				parse_flag_i(const char *format, int i, t_print *print,
								t_form *form);
int				parse_size_i(const char *format, int i, t_print *print);
int				parse_form_i(t_form *form, t_print *print, va_list vl,
								int i);
int				space_i(const char *format, int i, t_print *print);
int				last_i(const char *format, int i, t_print *print);
void			many_formats(t_form *form, t_print *print, va_list vl);
int				check_form(const char *format, int i);
int				get_perc(const char *format, int i);
void			last_d(t_form *form, t_print *print, va_list vl);
int				size(const char *format, int i, t_form *form, t_print *print);
int				size2(const char *format, int i, t_print *print);
int				size_zed(const char *format, int i, t_print *print);
void			print_plus(t_form *form, t_print *print, int num);
void			print_minus(t_form *form, t_print *print);
void			print_zed(t_form *form, t_print *print);
void			print_sharp(t_form *form, t_print *print, char *str);
void			print_space(t_form *form, t_print *print, long num);
int				print_just_i(t_form *form, t_print *print, intmax_t num,
								char *str);
void			print_space_min(int i, int z_len, intmax_t num, t_print *print);
void			print_just_zed(int y, int z_len, t_print *print);
void			print_just(t_form *form, t_print *print, intmax_t num,
								char *str);
void			form_d(t_form *form, t_print *print, va_list vl);
void			jd(t_form *form, t_print *print, va_list vl);
void			zd(t_form *form, t_print *print, va_list vl);
void			hd(t_form *form, t_print *print, va_list vl);
void			ld(t_form *form, t_print *print, va_list vl);
void			form_x(t_form *form, t_print *print, va_list vl);
void			reg_x(t_form *form, t_print *print, va_list vl);
void			jzx(t_form *form, t_print *print, va_list vl);
void			lx(t_form *form, t_print *print, va_list vl);
void			hx(t_form *form, t_print *print, va_list vl);
void			form_x_1(t_form *form, t_print *print, va_list vl);
void			reg_x_1(t_form *form, t_print *print, va_list vl);
void			jzx_1(t_form *form, t_print *print, va_list vl);
void			lx_1(t_form *form, t_print *print, va_list vl);
void			hx_1(t_form *form, t_print *print, va_list vl);
void			form_xo(t_form *form, t_print *print, char *str);
void			form_u(t_form *form, t_print *print, va_list vl);
void			form_p(t_form *form, t_print *print, va_list vl);
void			form_o(t_form *form, t_print *print, va_list vl);
void			form_o_1(t_form *form, t_print *print, va_list vl);

#endif
