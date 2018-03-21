/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 17:25:04 by anhuang           #+#    #+#             */
/*   Updated: 2018/02/06 17:25:05 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_percent(t_params para)
{
	if (para.flag.left)
		pc_putchar('%');
	if (para.width && !para.flag.zero)
		pf_spaces(para.width - 1);
	else if (para.width && para.flag.zero)
		pf_zero(para.width - 1);
	if (!para.flag.left)
		pc_putchar('%');
}

void	pf_spaces(int n)
{
	while (n > 0)
	{
		pc_putchar(' ');
		n--;
	}
}

void	pf_zero(int n)
{
	while (n > 0)
	{
		pc_putchar('0');
		n--;
	}
}
