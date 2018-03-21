/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 14:17:56 by anhuang           #+#    #+#             */
/*   Updated: 2018/03/05 10:34:25 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <wchar.h>
# include <limits.h>
# include <inttypes.h>
# include "libft.h"
# define BS 8
# define ABS(Value) ((Value < 0) ? -(Value) : (Value))

typedef enum		e_type
{
	CHAR, SHORT, MYINT, LONG, LL, DOUBLE,
}					t_type;

typedef struct		s_flag
{
	int				base;
	int				hash;
	int				spaces;
	int				left;
	int				neg;
	int				pos;
	int				zero;
}					t_flag;

typedef struct		s_params
{
	int				width;
	int				precision;
	char			type;
	char			converter;
	int				error;
	t_type			length;
	t_flag			flag;
}					t_params;

void				pc_core2(int *tmp, int *pos, int param);
void				pc_putchar(char c);
int					pc_print(int pos);
void				pc_putstr(char *str);
void				pf_pstr(char *c, t_params pa);
int					pc_core(char c, int param, int dpos);

int					pf_ft(va_list p, t_params para);
int					pf_ft2(va_list p, t_params para);
void				get_size(char *f, t_params *para, int *i);
void				get_flags(char *f, t_params *para, int *i);
void				get_type(char *f, t_params *para, int *i);
void				get_precision(char *f, t_params *para, int *i);
void				get_converter(char *f, t_params *para, int *i);

void				pf_pointer(va_list p, t_params pa);
int					ft_printf(char *format, ...);
short				is_flag(char c);
short				is_length(char c);

void				pf_parse(char *f, t_params *para, int *i);
void				pf_pint(long long nbr, t_params *pa);
void				pf_putint(va_list p, t_params pformat);

int					pf_char(va_list p, t_params para);
int					pf_big_char(va_list p, t_params para);
int					pf_string(va_list p, t_params para);
int					pf_big_string(va_list p, t_params para);

void				pf_hex(va_list p, t_params para);
void				pf_hex1(va_list p, t_params para);
void				pf_hex2(va_list p, t_params para);
void				pf_big_hex(va_list p, t_params para);
void				pf_big_hex2(va_list p, t_params para);
void				pf_big_hex1(va_list p, t_params pa);

void				pf_octal(va_list p, t_params para);
void				pf_octal1(va_list p, t_params pa);
void				pf_octal2(va_list p, t_params pa);
void				pf_big_octal(va_list p, t_params pa);
void				pf_big_octal1(va_list p, t_params pa);
void				pf_big_octal2(va_list p, t_params pa);

int					ft_strlen2(wchar_t *str, int width);
int					ft_strlen3(wchar_t *str);
void				pf_big_string3(t_params *pa, wchar_t *c);
void				pf_binary(va_list p, t_params para);
void				ft_binary22(t_params *pa, int i, int go);
void				pf_flag_bin(t_params *para, int i, long long nbr);
void				pf_binin(t_params *para, long long nbr, int i);

void				pf_percent(t_params para);
void				pf_putuint(va_list p, t_params pformat);
void				pf_double(va_list p, t_params pformat);
void				ft_remnant(double *nbr, t_params *para, int i);
void				pf_doublein(double nbr, t_params *para, int i);
void				pf_flag_double(int i, t_params pformat, double nbr);
void				pf_putshort(va_list p, t_params pa);
void				pf_pshort(short nbr, t_params *pa);
void				pf_putchard(va_list p, t_params pa);
void				pf_pchard(char nbr, t_params *pa);
void				pf_putlong(va_list p, t_params pa);
void				pf_plong(long nbr, t_params *pa);
long long			min_ll();
void				pf_prefix(t_params *pa);
void				pf_putuint(va_list p, t_params pa);

void				pf_zero(int n);
void				pf_spaces(int width);
unsigned long long	min_llu();
long long			min_ll();
long				min_l();
int					min_i();
short				min_s();
char				min_c();

#endif
