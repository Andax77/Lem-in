/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 15:52:07 by anhuang           #+#    #+#             */
/*   Updated: 2018/01/16 15:53:01 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_putchard(va_list p, t_params pa)
{
	char nbr;

	pa.width -= 1;
	if (pa.flag.left)
		pa.flag.zero = 0;
	nbr = (char)va_arg(p, int);
	pf_pint(nbr, &pa);
	if (pa.flag.left)
		pf_spaces(pa.width);
}

void	pf_pchard(char nbr, t_params *pa)
{
	int min;

	if ((min = (nbr == min_s())))
	{
		pa->flag.neg = 1;
		pf_pint((nbr - 1) / pa->flag.base, pa);
	}
	if (nbr < 0)
	{
		nbr = min ? nbr - 1 : -nbr;
		if (!min)
			pa->flag.neg = 1;
	}
	pa->width--;
	if ((nbr / pa->flag.base || (pa->flag.zero && pa->width > 0)) && !min)
		pf_pint(nbr / (char)pa->flag.base, pa);
	else if (!min)
	{
		if (!pa->flag.zero && !pa->flag.left)
			pf_spaces(pa->width);
		pf_prefix(pa);
	}
	pc_putchar(nbr % pa->flag.base + (min ? 49 : 48));
}
