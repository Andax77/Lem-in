/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_big_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 11:20:05 by anhuang           #+#    #+#             */
/*   Updated: 2018/01/27 11:20:08 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_mask(long nbr, int bit)
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

void	ft_binary(long nbr, t_params *para)
{
	int i;

	i = sizeof(long) * 4;
	while (nbr && nbr >> i == 0)
		i--;
	if (!nbr)
		i = 0;
	if (i < 7 || MB_CUR_MAX == 1)
		para->width -= 1;
	else if (i < 11)
		para->width -= 2;
	else if (i < 16)
		para->width -= 3;
	else if (i < 21)
		para->width -= 4;
	if (para->width && para->flag.left == 0)
		pf_spaces(para->width);
	ft_mask(nbr, i + 1);
}

int		pf_big_char(va_list p, t_params para)
{
	wchar_t			c;

	c = va_arg(p, wchar_t);
	if (c < 0 || (c > 0xd799 && c < 57344) || c >= 0x110000 || (c >= 0xdc00 &&
		c <= 0xdfff) || (MB_CUR_MAX == 1 && c > 255))
		return (1);
	ft_binary(c, &para);
	if (para.width && para.flag.left == 1)
		pf_spaces(para.width);
	return (0);
}
