/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_octal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 15:38:35 by anhuang           #+#    #+#             */
/*   Updated: 2018/02/05 15:38:36 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		pf_type_octal4(long long *nbr, t_params para)
{
	if (para.type == 'h')
		*nbr = (unsigned short)*nbr;
	else if (para.type == 'H')
		*nbr = (unsigned char)*nbr;
	else if (para.type == 'l')
		*nbr = (unsigned long)*nbr;
	else if (para.type == 'L')
		*nbr = (unsigned long long)*nbr;
	else if (para.type == 'j')
		*nbr = (uintmax_t) * nbr;
	else if (para.type == 'z')
		*nbr = (size_t)*nbr;
	else
		*nbr = (unsigned int)*nbr;
}

void		pf_octal(va_list p, t_params para)
{
	if (para.flag.pos)
		para.flag.pos = 0;
	if (para.type)
		pf_octal2(p, para);
	else
		pf_octal1(p, para);
}

static void	pf_puoctal(long nbr, t_params *pa)
{
	int lol;

	lol = 48;
	pa->width--;
	pa->precision--;
	if ((nbr / pa->flag.base || (pa->precision > 0)
	|| (pa->flag.zero && pa->width > 0)))
		pf_puoctal(nbr / (unsigned int)pa->flag.base, pa);
	else
	{
		if (!pa->flag.zero && !pa->flag.left)
			pf_spaces(pa->width);
		if (nbr % pa->flag.base == 0)
			pa->flag.hash = 0;
		pf_prefix(pa);
	}
	pc_putchar(nbr % pa->flag.base + lol);
}

void		pf_octal1(va_list p, t_params pa)
{
	long long nbr;

	pa.width--;
	if (pa.flag.left || pa.precision != -1)
		pa.flag.zero = 0;
	nbr = va_arg(p, long long);
	pf_type_octal4(&nbr, pa);
	if (pa.flag.hash)
		pa.width--;
	if (nbr > 0 && !pa.flag.pos)
		pa.width++;
	if (nbr == 0)
		pa.width++;
	if (pa.precision != 0 || nbr != 0 || pa.flag.hash)
	{
		if (pa.flag.hash && !nbr && !(pa.flag.hash = 0))
			pa.width++;
		pf_puoctal(nbr, &pa);
	}
	else
		pa.flag.left = 1;
	if (pa.flag.left)
		pf_spaces(pa.width);
}
