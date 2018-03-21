/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 11:43:18 by anhuang           #+#    #+#             */
/*   Updated: 2017/11/21 16:45:33 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*ptr1;
	char		*ptr;
	size_t		end;

	ptr1 = (char*)s;
	end = 0;
	if (!s)
		return (NULL);
	if (!(ptr = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (end < len)
	{
		ptr[end] = ptr1[start + end];
		end++;
	}
	ptr[end] = '\0';
	return (ptr);
}
