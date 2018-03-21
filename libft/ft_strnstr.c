/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 12:50:11 by anhuang           #+#    #+#             */
/*   Updated: 2017/11/21 11:52:15 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		a;

	a = 1;
	i = 0;
	if (little[i] == '\0')
		return ((char*)big);
	while (*big && len)
	{
		if (*big == little[i++])
			a++;
		else
		{
			i--;
			big = big - a + 1;
			len = len + a - 1;
			i = 0;
			a = 1;
		}
		if (little[i] == '\0')
			return ((char*)(big - i + 1));
		big++;
		len--;
	}
	return (NULL);
}
