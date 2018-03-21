/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 15:28:07 by anhuang           #+#    #+#             */
/*   Updated: 2017/11/16 18:20:52 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_size(int n)
{
	int		size;

	size = 1;
	if (n < 0)
	{
		size++;
		n = -n;
	}
	if (n == 0)
		return (size);
	while (n > 9)
	{
		n /= 10;
		size++;
	}
	return (size);
}

static char		*create_str(int size, int n, int i, char *str)
{
	if (i < 0)
	{
		str[0] = '-';
		str[size] = '\0';
		size--;
		while (size > 0)
		{
			str[size] = (n % 10) + '0';
			n /= 10;
			size--;
		}
		return (str);
	}
	str[size] = '\0';
	size--;
	while (size >= 0)
	{
		str[size] = (n % 10) + '0';
		n /= 10;
		size--;
	}
	return (str);
}

char			*ft_itoa(int n)
{
	char	*ptr;
	int		size;
	int		i;

	if (n == (-2147483648))
		return (ft_strdup("-2147483648"));
	size = ft_size(n);
	if (n < 0)
	{
		n = -n;
		i = -1;
	}
	else
		i = 0;
	if (!(ptr = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	if (n == 0)
	{
		ptr[0] = '0';
		ptr[1] = '\0';
		return (ptr);
	}
	return (create_str(size, n, i, ptr));
}
