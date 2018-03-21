/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_big_string2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 16:49:09 by anhuang           #+#    #+#             */
/*   Updated: 2018/02/26 16:49:10 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_binary22(t_params *pa, int i, int go)
{
	if ((i < 7 || MB_CUR_MAX == 1))
	{
		pa->precision -= pa->precision - 1 >= 0 ? 1 : 10;
		if (pa->precision >= 0 || go)
			pa->width -= 1;
	}
	else if (i < 11)
	{
		pa->precision -= pa->precision - 2 >= 0 ? 2 : 10;
		if (pa->precision >= 0 || go)
			pa->width -= 2;
	}
	else if (i < 16)
	{
		pa->precision -= pa->precision - 3 >= 0 ? 3 : 10;
		if (pa->precision >= 0 || go)
			pa->width -= 3;
	}
	else if (i < 21)
	{
		pa->precision -= pa->precision - 4 >= 0 ? 4 : 10;
		if (pa->precision >= 0 || go)
			pa->width -= 4;
	}
}

void	pf_big_string3(t_params *pa, wchar_t *c)
{
	if (pa->flag.zero && !pa->width)
		pf_zero(pa->width - pa->precision);
	else if (pa->flag.zero && ft_strlen2(c, pa->width) && pa->precision > 0)
		pf_zero(ft_strlen2(c, pa->width));
	else if (pa->flag.zero && pa->precision == 0)
	{
		pf_zero(pa->width);
		pa->width -= pa->width;
	}
	if (c && pa->width > ft_strlen3(c) && pa->precision == -1 && !pa->flag.left)
		pf_spaces(pa->width - ft_strlen3(c));
}
