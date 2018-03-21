/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_big_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 18:53:21 by anhuang           #+#    #+#             */
/*   Updated: 2018/01/30 18:53:23 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strlen2(wchar_t *str, int width)
{
	long	i;
	long	nbr;
	int		tmp;

	i = 0;
	while (str[i])
	{
		nbr = str[i++];
		tmp = sizeof(long) * 4;
		while (nbr && nbr >> tmp == 0)
			tmp--;
		if (tmp < 8 || MB_CUR_MAX == 1)
			width -= 1;
		else if (tmp < 11)
			width -= 2;
		else if (tmp < 16)
			width -= 3;
		else if (tmp < 21)
			width -= 4;
	}
	return (width);
}

int		ft_strlen3(wchar_t *str)
{
	int		width;
	long	i;
	long	nbr;
	int		tmp;

	width = 0;
	i = 0;
	while (str[i])
	{
		nbr = str[i++];
		tmp = sizeof(long) * 4;
		while (nbr && nbr >> tmp == 0)
			tmp--;
		if (tmp < 8 || MB_CUR_MAX == 1)
			width += 1;
		else if (tmp < 11)
			width += 2;
		else if (tmp < 16)
			width += 3;
		else if (tmp < 21)
			width += 4;
	}
	return (width);
}

void	ft_mask2(long nbr, int bit)
{
	if (bit < 8 || MB_CUR_MAX == 1)
		pc_putchar(0x00 | nbr);
	else if (bit < 12)
	{
		pc_putchar(0xc0 | (nbr >> 6));
		pc_putchar(0x80 | (nbr - ((nbr >> 6) << 6)));
	}
	else if (bit < 17)
	{
		pc_putchar(0xe0 | nbr >> 12);
		pc_putchar(0x80 | (nbr - ((nbr >> 12) << 12)) >> 6);
		pc_putchar(0x80 | (nbr - ((nbr >> 6) << 6)));
	}
	else if (bit < 22)
	{
		pc_putchar(0xf0 | (nbr >> 18));
		pc_putchar(0x80 | (nbr - ((nbr >> 18) << 18)) >> 12);
		pc_putchar(0x80 | (nbr - ((nbr >> 12) << 12)) >> 6);
		pc_putchar(0x80 | (nbr - ((nbr >> 6) << 6)));
	}
}

void	ft_binary2(long nbr, t_params *pa, int stop)
{
	int			i;
	static int	go;

	go = pa->precision == -1 || go == 1 ? 1 : 0;
	i = sizeof(long) * 4;
	while (nbr && nbr >> i == 0)
		i--;
	!nbr ? i = 0 : 1;
	ft_binary22(pa, i, go);
	if (pa->precision >= 0 || go)
		ft_mask2(nbr, i + 1);
	if (stop == 1)
		go = 0;
}

int		pf_big_string(va_list p, t_params pa)
{
	wchar_t			*c;
	long			i;

	i = 0;
	c = va_arg(p, wchar_t*);
	pf_big_string3(&pa, c);
	if (pa.precision == 0 && pa.width)
		pf_spaces(pa.width);
	while (c && c[i] && pa.precision)
	{
		if (c[i] < 0 || (c[i] > 0xd799 && c[i] < 57344) || c[i] >= 0x110000 ||
		(c[i] >= 0xdc00 && c[i] <= 0xdfff) || (MB_CUR_MAX == 1 && c[i] > 255))
			return (1);
		if (!c[i + 1])
			ft_binary2(c[i++], &pa, 1);
		else
			ft_binary2(c[i++], &pa, 0);
	}
	if (!c)
		pf_pstr("(null)", pa);
	if (pa.width && pa.flag.left == 1)
		pf_spaces(pa.width);
	return (0);
}
