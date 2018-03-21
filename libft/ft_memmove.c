/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 18:15:11 by anhuang           #+#    #+#             */
/*   Updated: 2017/11/16 15:31:55 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*ptr1;
	char	*ptr2;
	size_t	i;

	ptr1 = (char*)dst;
	ptr2 = (char*)src;
	i = 0;
	if (ptr2 < ptr1)
	{
		while (n--)
			ptr1[n] = ptr2[n];
	}
	else
		ft_memcpy(ptr1, ptr2, n);
	return (ptr1);
}
