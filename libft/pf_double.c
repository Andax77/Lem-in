/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_double.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 14:26:41 by anhuang           #+#    #+#             */
/*   Updated: 2018/01/26 14:26:43 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_good_nbr(double *nbr, t_params *para, int more)
{
	int					a;
	double				tmp;
	unsigned long int	i;
	double				divise;

	divise = 1;
	i = 0;
	tmp = *nbr;
	while ((int)i != para->precision + 1 && ++i)
		divise *= 10;
	(tmp * divise) / divise / 10 > 9 && (((unsigned long int)(divise * tmp) -
	(unsigned long int)(tmp * divise) / 10) % 10) != 1 ? para->width-- : 1;
	tmp = (unsigned long int)(tmp * (divise / 10) / 10) % 10;
	((unsigned long int)tmp >= 5 && more == 0) || tmp == 1 ? more = 1 : 1;
	*nbr -= (unsigned long int)tmp / divise;
	a = 0;
	tmp == 1 ? divise = 0 : 1;
	tmp = 1;
	while (a < para->precision && ++a && (i = 1))
		tmp /= 10;
	more == 1 ? *nbr += tmp : 1;
	more == 1 && a == 9 ? para->width -= 2 : 1;
	a = 0;
	while ((unsigned long int)*nbr >= i && ++a)
		i *= 10;
}

void	pf_flag_double(int i, t_params pformat, double nbr)
{
	if (pformat.width)
		++i;
	if (pformat.flag.pos)
		++i;
	if (pformat.flag.spaces && i++)
		pf_spaces(1);
	if (pformat.flag.left)
		pf_doublein(nbr, &pformat, 0);
	if (pformat.flag.zero == 0)
		pf_spaces(pformat.width - pformat.precision - i);
	else if (pformat.flag.zero == 1)
	{
		if (pformat.flag.pos == 1 && nbr > 0 && pformat.flag.neg == 0)
			pc_putchar('+');
		pf_zero(pformat.width - pformat.precision - i);
	}
	if (pformat.flag.left == 0)
		pf_doublein(nbr, &pformat, 0);
}

void	pf_double(va_list p, t_params pformat)
{
	double				tmp;
	double				nbr;
	int					i;

	i = 0;
	nbr = va_arg(p, double);
	pformat.precision == 0 ? pformat.precision = 6 : 1;
	pformat.precision == -1 ? pformat.precision = 0 : 1;
	if (nbr < 0)
	{
		pformat.flag.neg = 1;
		pc_putchar('-');
		nbr = -nbr;
	}
	ft_good_nbr(&nbr, &pformat, 0);
	tmp = nbr;
	while (tmp > 1 && ++i)
		tmp /= 10;
	pf_flag_double(i, pformat, nbr);
}

void	ft_remnant(double *nbr, t_params *para, int i)
{
	int		a;

	*nbr *= 10;
	while (i != -para->precision && nbr > 0)
	{
		a = 0;
		while ((unsigned long long)a < (unsigned long long)*nbr)
			++a;
		pc_putchar(a + '0');
		*nbr -= a;
		*nbr *= 10;
		i--;
	}
}

void	pf_doublein(double nbr, t_params *para, int i)
{
	unsigned long int	divise;
	double				tmp;
	int					a;

	divise = 1;
	i = 0;
	if (para->flag.pos == 1 && (para->flag.zero && para->flag.neg) == 0)
		pc_putchar('+');
	while (divise <= (unsigned long int)nbr && ++i)
		divise *= 10;
	divise /= 10;
	while (i-- && !(a = 0))
	{
		tmp = divise;
		while (divise <= (unsigned long int)nbr && ++a)
			divise += tmp;
		divise -= tmp;
		pc_putchar(a + '0');
		nbr -= divise;
		tmp /= 10;
		divise = tmp;
	}
	if (para->precision != 0 || para->flag.hash)
		pc_putchar('.');
	ft_remnant(&nbr, para, 0);
}
