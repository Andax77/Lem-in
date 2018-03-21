/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_big_hex2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 14:56:08 by anhuang           #+#    #+#             */
/*   Updated: 2018/02/15 14:56:09 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			pf_type_hex3(unsigned long long *nbr, t_params para)
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

static void		pf_big_puhex2(unsigned long nbr, t_params *pa)
{
	int	lol;

	lol = 48;
	pa->width--;
	pa->precision--;
	if (pa->flag.hash == 1 && nbr && pa->flag.hash++)
	{
		pc_putchar('0');
		pc_putchar('X');
	}
	if ((nbr / pa->flag.base || (pa->precision > 0)
	|| (pa->flag.zero && pa->width > 0)))
		pf_big_puhex2(nbr / (unsigned int)pa->flag.base, pa);
	else
	{
		if (!pa->flag.zero && !pa->flag.left)
			pf_spaces(pa->width);
		if (nbr % pa->flag.base == 0)
			pa->flag.hash = 0;
		pf_prefix(pa);
	}
	if (nbr % pa->flag.base > 9)
		lol += 7;
	pc_putchar(nbr % pa->flag.base + lol);
}

void			pf_big_hex2(va_list p, t_params pa)
{
	unsigned long long	nbr;

	pa.flag.pos = 0;
	if (pa.flag.left || pa.precision != -1)
		pa.flag.zero = 0;
	nbr = va_arg(p, unsigned long long);
	pf_type_hex3(&nbr, pa);
	if (pa.precision != 0 || nbr != 0)
		pf_big_puhex2(nbr, &pa);
	else
		pa.flag.left = 1;
	if (pa.flag.left)
		pf_spaces(pa.width);
}
