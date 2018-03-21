/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 18:20:51 by anhuang           #+#    #+#             */
/*   Updated: 2018/02/26 18:20:53 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		get_flags(char *f, t_params *para, int *i)
{
	while (f[*i])
	{
		if (f[*i] == '#')
			para->flag.hash = 1;
		else if (f[*i] == '0')
			para->flag.zero = 1;
		else if (f[*i] == '-')
			para->flag.left = 1;
		else if (f[*i] == '+')
			para->flag.pos = 1;
		else if (f[*i] == ' ')
			para->flag.spaces = 1;
		else
			return ;
		++(*i);
	}
}

void		get_size(char *f, t_params *para, int *i)
{
	if (f[*i] >= '0' && f[*i] <= '9')
	{
		para->width = ft_atoi(f + *i);
		while (f[*i] >= '0' && f[*i] <= '9')
			++(*i);
	}
}

void		get_precision(char *f, t_params *para, int *i)
{
	if (f[*i] == '.')
	{
		++(*i);
		if (f[*i] >= '0' && f[*i] <= '9')
		{
			para->precision = ft_atoi(f + *i);
			while (f[*i] >= '0' && f[*i] <= '9')
				++(*i);
		}
		else
			para->precision = 0;
		if (para->flag.hash && para->precision == -1)
			para->width--;
	}
	else
		para->precision = -1;
}

void		get_type(char *f, t_params *para, int *i)
{
	if (f[*i] == 'h')
	{
		para->type = 'h';
		if (f[*i + 1] == 'h')
		{
			para->type = 'H';
			++(*i);
		}
	}
	else if (f[*i] == 'l')
	{
		para->type = 'l';
		if (f[*i + 1] == 'l')
		{
			para->type = 'L';
			++(*i);
		}
	}
	else if (f[*i] == 'j')
		para->type = 'j';
	else if (f[*i] == 'z')
		para->type = 'z';
	else
		return ;
	++(*i);
}

void		get_converter(char *f, t_params *para, int *i)
{
	if (ft_strchr("bsSpPdDioOuUxXcCFf%", f[*i]))
		para->converter = f[*i];
	else
	{
		if (para->flag.zero)
			pf_zero(para->width - 1);
		else if (para->width && !para->flag.left)
			pf_spaces(para->width - 1);
		--(*i);
	}
}
