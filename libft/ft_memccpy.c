/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:32:43 by anhuang           #+#    #+#             */
/*   Updated: 2017/11/16 12:27:49 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char	*ptr1;
	char	*ptr2;
	size_t	t;

	if (!dest && !src)
		return (NULL);
	t = 0;
	ptr1 = (char*)dest;
	ptr2 = (char*)src;
	while (n > t)
	{
		ptr1[t] = ptr2[t];
		if (ptr1[t] == (char)c)
			return (ptr1 + t + 1);
		t++;
	}
	return (NULL);
}
