/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 14:58:42 by anhuang           #+#    #+#             */
/*   Updated: 2018/01/26 14:58:43 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_pstr(char *c, t_params pa)
{
	int		i;
	int		len;

	len = ft_strlen(c);
	if (len >= pa.precision && pa.precision >= 0)
		len = pa.precision;
	if (!pa.flag.left && !pa.flag.zero && pa.width)
		pf_spaces(pa.width - len);
	else if (pa.width && pa.flag.zero)
		pf_zero(pa.width - len);
	i = 0;
	while (c[i] && i < len)
		pc_putchar(c[i++]);
	if (pa.flag.left)
		pf_spaces(pa.width - len);
}

int		pf_string(va_list p, t_params pa)
{
	char	*c;

	if (pa.type == 'l')
		return (pf_big_string(p, pa));
	c = va_arg(p, char*);
	if (c)
		pf_pstr(c, pa);
	else
		pf_pstr("(null)", pa);
	return (0);
}
