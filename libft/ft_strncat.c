/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:19:54 by anhuang           #+#    #+#             */
/*   Updated: 2017/11/16 12:06:26 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t		a;
	int			i;

	a = 0;
	i = 0;
	while (dest[i] != '\0')
		i++;
	while (n != a && src[a])
		dest[i++] = src[a++];
	dest[i] = '\0';
	return (dest);
}
