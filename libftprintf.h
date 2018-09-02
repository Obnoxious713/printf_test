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

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

/*
** ------ LIBRARIES ------
*/
# include "libft/libft.h"
# include <stdarg.h>

/*
** ------ TYPEDEFS ------
*/
typedef struct	s_type
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
}				t_type;

typedef struct	s_print
{
	int			plus;
	int			minus;
	int			sharp;
	int			zero;
	int			l_1;
	int			l_2;
	int			h_1;
	int			h_2;
	int			j;
	int			z;
	int			loc;
	int			size;
	int			just_size;
	int			percent;
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
int				ft_printf(const char *format, ...);
//!
void			print_flags_start(t_type *type, t_print *print,
							long num, char *str);
void			print_flags_end(t_type *type, t_print *print,
								long num, char *str);
//!
void			ft_putnbr_pr(int num, t_print *print);
void			ft_putstr_min(char *str, t_print *print);
void			ft_putstr_prec(char *str, t_print *print);
void			ft_putulong(unsigned long long n, t_print *print);
void			ft_putwstr_prec(wchar_t *str, t_print *print);
int				ft_wstrlen(wchar_t *str);
//!
int				num_len_i(int num);
int				num_len_l(long num);
void			osx_len(t_type *type, t_print *print, char *str);
void			zero_len(t_type *type, int num, char *str);
//!
int				get_loc(const char *format, int loc, t_print *print);
int				flag_loc(const char *format, int loc,
							t_print *print, t_type *type);
int				size_loc(const char *format, int loc, t_print *print);
int				space_loc(const char *format, int loc, t_print *print);
int				last_loc(const char *format, int loc, t_print *print);
//!
int				parse_flag(const char *format, int loc, t_print *print);
int				parse_loc(const char *format, int loc, t_type *type,
							t_print *print);
int				parse_len(const char *format, int i, t_print *print);
int				parse_flag_loc(t_type *type, t_print *print, va_list vlst, int i);
//!
int				get_tsize(const char *format, int loc,
						t_type *type, t_print *print);
int				get_psize(const char *format, int loc, t_print *print);
int				get_zsize(const char *format, int loc, t_print *print);
//!
void			print_prec(t_type *type, t_print *print,
								intmax_t num, char *str);
void			print_space_prec(int loc, int z_len, t_print *print);
void			print_zero_prec(int z_len, t_print *print);
int				prec_len(t_type *type, t_print *print,
							intmax_t num, char *str);
//!
void			print_space(t_type *type, t_print *print, long num);
void			print_sharp(t_type *type, t_print *print, char *str);
void			print_zero(t_type *type, t_print *print);
void			print_minus(t_type *type, t_print *print);
void			print_plus(t_type *type, t_print *print, int num);
//!
void			start(const char *format, t_type *type, t_print *print,
						va_list vlstst);
void			def_val(t_print *print, t_type *type);
void			def_val2(t_print *print);
//!
void			type_c(t_type *type, t_print *print, va_list vlst);
void			type_s(t_type *type, t_print *print, va_list vlst);
void			type_s_1(t_type *type, t_print *print, va_list vlst);
void			type_p(t_type *type, t_print *print, va_list vlst);
//!
void			type_x_1(t_type *type, t_print *print, va_list vlst);
void			reg_x_1(t_type *type, t_print *print, va_list vlst);
void			jzx_1(t_type *type, t_print *print, va_list vlst);
void			lx_1(t_type *type, t_print *print, va_list vlst);
void			hx_1(t_type *type, t_print *print, va_list vlst);
//!
void			type_x(t_type *type, t_print *print, va_list vlst);
void			reg_x(t_type *type, t_print *print, va_list vlst);
void			jzx(t_type *type, t_print *print, va_list vlst);
void			lx(t_type *type, t_print *print, va_list vlst);
void			hx(t_type *type, t_print *print, va_list vlst);
//!
void			type_u(t_type *type, t_print *print, va_list vlst);
void			type_o(t_type *type, t_print *print, va_list vlst);
void			type_o_1(t_type *type, t_print *print, va_list vlst);
void			type_d_1(t_type *type, t_print *print, va_list vlst);
void			last_d(t_type *type, t_print *print, va_list vlst);
//!
void			type_d(t_type *type, t_print *print, va_list vlst);
void			ld(t_type *type, t_print *print, va_list vlst);
void			hd(t_type *type, t_print *print, va_list vlst);
void			zd(t_type *type, t_print *print, va_list vlst);
void			jd(t_type *type, t_print *print, va_list vlst);
//!
int				get_type(const char *format, int i, t_type *type);
int				get_type2(const char *format, int i, t_type *type);
int				get_percent(const char *format, int i);
int				check_type(const char *format, int i);
void			many_types(t_type *type, t_print *print, va_list vlst);
//!
#endif
