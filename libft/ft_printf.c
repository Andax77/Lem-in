/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 11:54:44 by anhuang           #+#    #+#             */
/*   Updated: 2018/01/16 11:55:03 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(char *format, ...)
{
	va_list		p;
	t_params	para;
	int			i;

	va_start(p, format);
	if (!(i = 0) && !format[i])
		return (pc_print(-1));
	while (format[i])
	{
		if (format[i] == '%')
		{
			pf_parse(format, &para, &i);
			if (pf_ft(p, para))
			{
				pc_core(0, 4, 0);
				return (pc_print(-2));
			}
			pc_core(0, 5, 0);
		}
		else
			pc_putchar(format[i]);
		i++;
	}
	va_end(p);
	return (pc_print(-1));
}

int		pf_ft2(va_list p, t_params para)
{
	if (para.converter == 'O' && (para.flag.base = 8))
		pf_big_octal(p, para);
	else if (para.converter == 'u')
		pf_putuint(p, para);
	else if (para.converter == 'U' && (para.type = 'l'))
		pf_putuint(p, para);
	else if (para.converter == 'x' && (para.flag.base = 16))
		pf_hex(p, para);
	else if (para.converter == 'X' && (para.flag.base = 16))
		pf_big_hex(p, para);
	else if (para.converter == 'c')
		return (pf_char(p, para));
	else if (para.converter == 'C')
		return (pf_big_char(p, para));
	else if (para.converter == 'f')
		pf_double(p, para);
	else if (para.converter == 'F')
		pf_double(p, para);
	else if (para.converter == '%')
		pf_percent(para);
	return (0);
}

int		pf_ft(va_list p, t_params para)
{
	if (para.converter == 'b')
		pf_binary(p, para);
	else if (para.converter == 's')
		return (pf_string(p, para));
	else if (para.converter == 'S')
		return (pf_big_string(p, para));
	else if (para.converter == 'p')
		pf_pointer(p, para);
	else if (para.converter == 'd')
		pf_putint(p, para);
	else if (para.converter == 'D' && (para.type = 'l'))
		pf_putint(p, para);
	else if (para.converter == 'i')
		pf_putint(p, para);
	else if (para.converter == 'o' && (para.flag.base = 8))
		pf_octal(p, para);
	else if (pf_ft2(p, para))
		return (1);
	return (0);
}

void	pf_parse(char *f, t_params *para, int *i)
{
	if (f[*i + 1])
	{
		++(*i);
		ft_bzero(para, sizeof(t_params));
		para->flag.base = 10;
		get_flags(f, para, i);
		get_size(f, para, i);
		get_precision(f, para, i);
		get_type(f, para, i);
		get_converter(f, para, i);
	}
}
