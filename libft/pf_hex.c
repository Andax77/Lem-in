/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 14:08:54 by anhuang           #+#    #+#             */
/*   Updated: 2018/02/02 14:09:04 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			pf_type_hex4(long long *nbr, t_params para)
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

void			pf_hex(va_list p, t_params para)
{
	if (para.type)
		pf_hex2(p, para);
	else
		pf_hex1(p, para);
}

static void		pf_puhex(long nbr, t_params *pa)
{
	int	lol;

	lol = 48;
	pa->width--;
	pa->precision--;
	if ((nbr / pa->flag.base || (pa->precision > 0)
	|| (pa->flag.zero && pa->width > 0)))
		pf_puhex(nbr / (unsigned int)pa->flag.base, pa);
	else
	{
		if (!pa->flag.zero && !pa->flag.left)
			pf_spaces(pa->width);
		pf_prefix(pa);
	}
	if (nbr % pa->flag.base > 9)
		lol += 39;
	pc_putchar(nbr % pa->flag.base + lol);
}

void			pf_hex1(va_list p, t_params pa)
{
	long long	nbr;

	pa.flag.pos = 0;
	if (pa.flag.left || pa.precision != -1)
		pa.flag.zero = 0;
	nbr = va_arg(p, long long);
	pf_type_hex4(&nbr, pa);
	if (pa.flag.hash)
		pa.width -= 2;
	if (pa.precision != 0 || nbr != 0)
	{
		if (pa.flag.hash && !nbr && !(pa.flag.hash = 0))
			pa.width += 2;
		pf_puhex(nbr, &pa);
	}
	else
		pa.flag.left = 1;
	if (pa.flag.left)
		pf_spaces(pa.width);
}
