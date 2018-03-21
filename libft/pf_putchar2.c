/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putchar2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 14:20:18 by anhuang           #+#    #+#             */
/*   Updated: 2018/02/19 14:20:28 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				pc_putchar(char c)
{
	pc_core(c, 1, 0);
}

void				pc_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		pc_core(str[i], 1, 0);
		i++;
	}
}
