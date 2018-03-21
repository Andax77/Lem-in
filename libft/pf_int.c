/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 18:44:52 by anhuang           #+#    #+#             */
/*   Updated: 2018/02/16 18:44:53 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_type_int2(long long *nbr, t_params *para)
{
	if (para->type == 'h')
		*nbr = (short)*nbr;
	else if (para->type == 'H')
		*nbr = (char)*nbr;
	else if (para->type == 'l' || para->type == 'L' || para->converter == 'D')
		*nbr = (long)*nbr;
	else if (para->type == 'j')
		*nbr = (intmax_t) * nbr;
	else if (para->type == 'z')
		*nbr = (size_t)*nbr;
	else
		*nbr = (int)*nbr;
}

void	pf_putint(va_list p, t_params pa)
{
	long long nbr;

	pa.width -= 1;
	pa.flag.spaces && !pa.flag.pos ? pa.flag.pos = 2 : 1;
	if (pa.flag.left || pa.precision != -1)
		pa.flag.zero = 0;
	nbr = va_arg(p, long long);
	pf_type_int2(&nbr, &pa);
	if (nbr >= 0 && !pa.flag.pos)
		pa.width++;
	if (pa.precision != 0 || nbr != 0)
		pf_pint(nbr, &pa);
	else if ((pa.flag.pos == 1 || pa.flag.pos == 2))
	{
		pf_spaces(pa.flag.left ? 0 : pa.width);
		pc_putchar(pa.flag.pos == 1 ? '+' : ' ');
		pa.width--;
	}
	else
		pa.flag.left = 1;
	if (nbr == min_ll())
		pa.width--;
	if (pa.flag.left)
		pf_spaces(pa.width);
}

void	pf_pint(long long nbr, t_params *pa)
{
	long long min;

	if ((min = (nbr == min_ll())))
	{
		pa->flag.neg = 1;
		pa->width--;
		pa->precision--;
		pf_pint((nbr - 1) / pa->flag.base, pa);
	}
	if (nbr < 0 && (nbr = min ? nbr - 1 : -nbr))
		pa->flag.neg = min ? pa->flag.neg : 1;
	pa->width--;
	pa->precision--;
	if ((nbr / pa->flag.base || (pa->precision > 0)
	|| (pa->flag.zero && pa->width > 0)) && !min)
		pf_pint(nbr / (int)pa->flag.base, pa);
	else if (!min)
	{
		pf_spaces(!pa->flag.zero && !pa->flag.left ? pa->width : 0);
		pf_prefix(pa);
	}
	min ? min = 49 : 1;
	min != 49 ? min = 48 : 1;
	pc_putchar(nbr % pa->flag.base + min);
}

void	pf_prefix(t_params *pa)
{
	if (pa->flag.neg)
		pc_putchar('-');
	else if (pa->flag.pos == 1)
		pc_putchar('+');
	else if (pa->flag.pos == 2)
		pc_putchar(' ');
	else if (pa->flag.hash == 1 && pa->flag.base == 8 && pa->flag.hash++)
		pc_putchar('0');
	else if (pa->flag.hash == 1 && pa->flag.base == 16 && pa->flag.hash++)
	{
		pc_putchar('0');
		pc_putchar(pa->converter == 'x' || pa->converter == 'p' ? 'x' : 'X');
	}
}
