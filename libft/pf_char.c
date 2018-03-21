/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 14:27:15 by anhuang           #+#    #+#             */
/*   Updated: 2018/01/26 14:27:17 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_char(va_list p, t_params para)
{
	char	c;

	if (para.type == 'l')
		return (pf_big_char(p, para));
	c = va_arg(p, int);
	if (para.width && para.flag.left == 0 && !para.flag.zero)
		pf_spaces(para.width - 1);
	else if (para.width && para.flag.zero)
		pf_zero(para.width - 1);
	if (!c)
		pc_putchar(0);
	else
		pc_putchar(c);
	if (para.width && para.flag.left == 1)
		pf_spaces(para.width - 1);
	return (0);
}
