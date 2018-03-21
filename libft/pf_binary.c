/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_binary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 14:56:24 by anhuang           #+#    #+#             */
/*   Updated: 2018/02/15 14:56:26 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		pf_flag_bin(t_params *pa, int i, long long nbr)
{
	nbr == 0 ? i++ : 1;
	if (nbr == 0 && pa->flag.zero)
		i -= 2;
	pa->flag.hash == 1 ? i += 2 : 1;
	pa->width > 0 ? i++ : 1;
	pa->precision > i && pa->flag.zero > 0 ? i-- : 1;
	if (pa->flag.left)
		pf_binin(pa, nbr, 1);
	if ((pa->flag.zero == 0 && pa->precision == -1) || nbr == 0)
		pf_spaces(pa->width - pa->precision - i);
	else if (pa->flag.zero && !pa->flag.hash)
		pf_zero(ABS(pa->width - pa->precision) - i);
	if (pa->flag.hash && pa->precision > 0 && nbr != 0 && !(pa->precision < i))
		pf_spaces(pa->width - pa->precision - 2);
	else if (pa->precision && pa->width > pa->precision && !(pa->precision < i))
		pf_spaces(pa->width - pa->precision);
	else if (pa->width > i && pa->flag.hash && pa->precision >= 0)
		pf_spaces(pa->width - i + 1);
	if (pa->flag.left == 0)
		pf_binin(pa, nbr, 1);
}

void		pf_binary(va_list p, t_params para)
{
	long long	nbr;
	int			i;
	long long	divise;

	divise = 1;
	i = 0;
	nbr = va_arg(p, long long);
	while (nbr != 0 && nbr / divise > 0 && ++i)
		divise *= 2;
	pf_flag_bin(&para, i, nbr);
	return ;
}

void		pf_mini_flag_bin(t_params *para, int i, long long nbr)
{
	if (para->flag.hash && --i)
	{
		pc_putchar('0');
		pc_putchar('b');
	}
	if (nbr == 0 && para->flag.hash)
		i++;
	if (para->width < para->precision && para->flag.hash)
		pf_zero(para->precision - i);
	else if (para->flag.hash && para->precision > i + 2 && nbr != 0)
		pf_zero(para->precision - i);
	else if (para->flag.hash && para->flag.zero && para->precision == -1)
		pf_zero(para->width - i - 2);
	else if (para->flag.hash && para->precision > i)
		pf_zero(para->precision - i);
	else if (!para->flag.hash && para->precision && nbr == 0)
		pf_zero(para->precision - 1);
	else if (para->width > para->precision && !para->flag.hash)
		pf_zero(para->precision - i + 1);
}

void		pf_binin(t_params *para, long long nbr, int i)
{
	static char	*bin;
	long long	tmp;
	int			a;
	long long	tmp2;

	bin = "0123456789abcdef";
	tmp = 1;
	while (nbr / tmp > 0 && ++i)
		tmp *= 2;
	tmp = 2;
	pf_mini_flag_bin(para, i, nbr);
	if (nbr == 0 && para->precision == 0)
		return ;
	while (nbr >= tmp)
		tmp *= 2;
	tmp /= 2;
	while (tmp && !(a = 0))
	{
		tmp2 = tmp;
		while (nbr >= tmp && tmp2 > 0 && ++a)
			tmp += tmp2;
		pc_putchar(bin[a]);
		nbr -= tmp - tmp2;
		tmp = tmp2 / 2;
	}
}
