/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:09:44 by anhuang           #+#    #+#             */
/*   Updated: 2018/01/16 10:30:28 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_manage(int result, int negative)
{
	if (negative == 1)
		return (-result);
	else
		return (result);
}

int				ft_atoi(const char *str)
{
	int		a;
	int		result;
	int		negative;

	a = 0;
	negative = 0;
	result = 0;
	while (str[a] == ' ' || str[a] == '\n' || str[a] == '\v' || str[a] == '\f'
			|| str[a] == '\r' || str[a] == '\t')
		a++;
	if (str[a] == '+')
		a++;
	if (str[a] == '-')
	{
		if (str[a - 1] == '+' || str[a - 1] == '-')
			return (0);
		negative = 1;
		a++;
	}
	while ((str[a] <= '9') && (str[a] >= '0'))
	{
		result = result * 10;
		result += (str[a++] - 48);
	}
	return (ft_manage(result, negative));
}
